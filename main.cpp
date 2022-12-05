#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
    // Objective A: Modify the “studentData Table” to include your personal information as the last item.
    // Objective B: Create 5 files: degree.h, student.h, student.cpp, roster.h, roster.cpp

    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,Kevin,Richard,krric669@wgu.edu,37, 4, 24, 30,SOFTWARE"};
    const int rosterSize = 5;
    // Objective F-2
    Roster classRoster(rosterSize);
    for (int i = 0; i < 5; i++)
        // Objective F-3
        classRoster.parse(studentData[i]);

    // Objective F-1
    cout << endl
         << "C867 Scripting and Programming - Applications" << endl
         << "C++" << endl
         << "Kevin Richard" << endl
         << "010762178" << endl
         << endl
         << endl;

    // Objective F-4
    cout << "Print All Students:\n";
    classRoster.printAll();

    cout << "\nInvalid Emails:\n";
    classRoster.printInvalidEmails();

    cout << "\nAverage days in Course:\n";
    for (int i = 0; i < rosterSize; i++)
    {
        string currentStudent = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(currentStudent);
    }

    cout << "\nPrint by Degree:\n";
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << "\nRemoving A3:\n";
    classRoster.remove("A3");

    cout << "\nPrinting All Students:\n";
    classRoster.printAll();

    cout << "\nAttempting to Remove A3 again:\n";
    classRoster.remove("A3");

    return 0;
}
