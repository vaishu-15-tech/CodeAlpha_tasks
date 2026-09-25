#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int courses;
    float grade, credits;
    float totalCredits = 0;
    float totalGradePoints = 0;

    cout << "Enter the number of courses: ";
    cin >> courses;

    // Arrays to store course details
    float grades[courses];
    float creditHours[courses];

    for (int i = 0; i < courses; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade: ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        totalCredits += creditHours[i];
        totalGradePoints += grades[i] * creditHours[i];
    }

    // Calculate GPA
    float GPA = totalGradePoints / totalCredits;

    // Display course details
    cout << "\n========== COURSE DETAILS ==========\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < courses; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credit Hours: " << creditHours[i] << endl;
    }

    // Display final result
    cout << "\n========== RESULT ==========\n";
    cout << "Total Credits      : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << "Semester GPA       : " << GPA << endl;
    cout << "Overall CGPA       : " << GPA << endl;

    return 0;
}