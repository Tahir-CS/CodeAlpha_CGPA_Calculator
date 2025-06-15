🎓 CGPA Calculator — C++ (with std::map Grade Conversion)
This project is a C++ console application that calculates the GPA for each semester and the cumulative CGPA across multiple semesters. It uses std::map to convert letter grades (like A, B+, C-) to GPA points, and stores the final report in a file.

📌 Features
📘 Supports multiple semesters

🎯 GPA calculation for each semester

📊 Final CGPA computation

🧠 Letter grade to grade point conversion using std::map

💾 Outputs results to a text file (cgpa_report.txt)

🔁 Input validation for incorrect grades

🧮 Grade Scale Used (4.0 GPA System)
Letter Grade	Grade Point
A+, A	4.0
A−	3.7
B+	3.3
B	3.0
B−	2.7
C+	2.3
C	2.0
C−	1.7
D+	1.3
D	1.0
F	0.0

🚀 How to Run
Clone or download the repository.

Open the .cpp file in your C++ IDE (e.g., Code::Blocks, Visual Studio, etc.) or compile using terminal:

bash
Copy
Edit
g++ cgpa_calculator.cpp -o cgpa_calculator
./cgpa_calculator
Follow the input prompts to enter semester details.

📂 Output
Displays GPA for each semester and final CGPA.

Saves the report in a file called cgpa_report.txt in the same directory.

🧾 Sample Input & Output
yaml
Copy
Edit
Enter number of semesters: 2

📘 Semester 1:
Enter number of courses: 2
  Course 1 letter grade: A
  Course 1 credit hours: 3
  Course 2 letter grade: B+
  Course 2 credit hours: 4
✅ GPA for Semester 1: 3.51

📘 Semester 2:
Enter number of courses: 2
  Course 1 letter grade: B
  Course 1 credit hours: 3
  Course 2 letter grade: C+
  Course 2 credit hours: 2
✅ GPA for Semester 2: 2.88

🎓 Final CGPA: 3.25
📄 Report saved in 'cgpa_report.txt'
🛠 Technologies Used
C++17

STL (map, vector, fstream, etc.)

📬 Contact
Made with 💻 by Muhammad Tahir
📧 [Add your email or LinkedIn if needed
