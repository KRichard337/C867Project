#include "student.h"
#include <iomanip>

using namespace std;
// Objective D-1
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysSize; i++)
        this->daysInCourse[i] = 0;
}
// Objective D-2D
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->degreeProgram = degreeProgram;
    for (int i = 0; i < daysSize; i++)
        this->daysInCourse[i] = daysInCourse[i];
}

// Objective D-2A
string Student::getStudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}
string Student::getEmailAddress()
{
    return emailAddress;
}
int Student::getAge()
{
    return age;
}
int *Student::getDaysInCourse()
{
    return daysInCourse;
}
DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

// Objective D-2B
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}
void Student::setAge(int age)
{
    this->age = age;
}
void Student::setDaysInCourse(int days1, int days2, int days3)
{
    this->daysInCourse[0] = days1;
    this->daysInCourse[1] = days2;
    this->daysInCourse[2] = days3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}
// Objective D-2E
void Student::printStudent()
{
    string degreeText;
    if (degreeProgram == SECURITY)
    {
        degreeText = "SECURITY";
    }
    else if (degreeProgram == SOFTWARE)
    {
        degreeText = "SOFTWARE";
    }
    else if (degreeProgram == NETWORK)
    {
        degreeText = "NETWORK";
    }

    cout << setw(4) << studentID
         << " First Name:" << setw(10) << firstName
         << " Last Name: " << setw(10) << lastName
         << " Age: " << left << setw(4) << age
         << " daysInCourse: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}\t"
         << " Degree Program: " << setw(10) << degreeText << endl;
}