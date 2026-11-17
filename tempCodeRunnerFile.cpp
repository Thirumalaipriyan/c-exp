#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
    string name;
    int marks;
    char grade;
};

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> students[i].name;

        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> students[i].marks;

        students[i].grade = ' ';
    }

    // Lambda to assign grades
    auto assignGrade = [](Student &s)
    {
        if (s.marks >= 90)
            s.grade = 'A';
        else if (s.marks >= 80)
            s.grade = 'B';
        else if (s.marks >= 70)
            s.grade = 'C';
        else
            s.grade = 'F';
    };

    for_each(students.begin(), students.end(), assignGrade);

    // Sort by marks (highest first)
    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b)
         {
             return a.marks > b.marks;
         });

    cout << endl;
    cout << "Name\tMarks\tGrade" << endl;
    cout << "---------------------\n";

    for (const auto &s : students)
    {
        cout << s.name << "\t"
             << s.marks << "\t"
             << s.grade << endl;
    }

    return 0;
}