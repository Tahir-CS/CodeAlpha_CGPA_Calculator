#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Course {
    string letterGrade;
    float gradePoint;
    int credit;
};

struct Semester {
    vector<Course> courses;
    float semesterGPA;
    int totalCredits;
};

// Function to convert letter grades to 4.0 GPA scale
float convertLetterToPoint(const string& grade) {
    string g = grade;
    transform(g.begin(), g.end(), g.begin(), ::toupper); // Normalize case

    map<string, float> gradeMap = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };

    if (gradeMap.count(g)) return gradeMap[g];
    else return -1.0; // Invalid
}

int main() {
    int numSemesters;
    float cumulativeGradePoints = 0.0;
    int cumulativeCredits = 0;

    ofstream outFile("cgpa_report.txt");

    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    vector<Semester> semesters(numSemesters);

    for (int s = 0; s < numSemesters; ++s) {
        int numCourses;
        float semesterGradePoints = 0.0;
        int semesterCredits = 0;

        cout << "\n📚 Semester " << s + 1 << ":\n";
        cout << "Enter number of courses: ";
        cin >> numCourses;

        semesters[s].courses.resize(numCourses);

        for (int i = 0; i < numCourses; ++i) {
            string letter;
            int credit;

            cout << "  Course " << i + 1 << " letter grade (e.g., A, B+, C-): ";
            cin >> letter;

            float point = convertLetterToPoint(letter);
            while (point == -1.0) {
                cout << "❌ Invalid grade. Re-enter (e.g., A, B+, C-): ";
                cin >> letter;
                point = convertLetterToPoint(letter);
            }

            cout << "  Course " << i + 1 << " credit hours: ";
            cin >> credit;

            semesters[s].courses[i] = {letter, point, credit};

            semesterGradePoints += point * credit;
            semesterCredits += credit;
        }

        semesters[s].semesterGPA = semesterGradePoints / semesterCredits;
        semesters[s].totalCredits = semesterCredits;

        cumulativeGradePoints += semesterGradePoints;
        cumulativeCredits += semesterCredits;

        cout << fixed << setprecision(2);
        cout << "✅ GPA for Semester " << s + 1 << ": " << semesters[s].semesterGPA << "\n";

        // Save to file
        outFile << "Semester " << s + 1 << " GPA: " << semesters[s].semesterGPA << "\n";
    }

    if (cumulativeCredits > 0) {
        float cgpa = cumulativeGradePoints / cumulativeCredits;
        cout << "\n🎓 Final CGPA (All Semesters): " << fixed << setprecision(2) << cgpa << "\n";
        outFile << "Final CGPA: " << cgpa << "\n";
    } else {
        cout << "⚠️ Error: No credits found. CGPA cannot be calculated.\n";
        outFile << "Error: CGPA could not be calculated due to missing credit data.\n";
    }

    outFile.close();
    cout << "\n📄 Report saved to 'cgpa_report.txt'\n";

    return 0;
}
