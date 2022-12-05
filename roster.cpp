#include "roster.h"
#include <regex>
using namespace std;

// Objective E-1
Roster::Roster()
{
    this->classSize = 0;
    this->classRosterArray = nullptr;
    this->lastIndex = -1;
}

Roster::Roster(int classSize)
{
    this->classSize = classSize;
    this->classRosterArray = new Student *[classSize];
    this->lastIndex = -1;
}

// Objective E-2
void Roster::parse(string row)
{
    if (lastIndex < classSize)
    {
        lastIndex++;
        int rhs = row.find(",");
        string studentID = row.substr(0, rhs);

        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string studentFirst = row.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string studentLast = row.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string studentEmail = row.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int studentAge = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int numdays1 = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int numdays2 = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int numdays3 = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sDegree = row.substr(lhs, rhs - lhs);
        DegreeProgram degreeProgram;
        if (sDegree == "SOFTWARE")
        {
            degreeProgram = SOFTWARE;
        }
        else if (sDegree == "NETWORK")
        {
            degreeProgram = NETWORK;
        }
        else if (sDegree == "SECURITY")
        {
            degreeProgram = SECURITY;
        }
        add(studentID, studentFirst, studentLast, studentEmail, studentAge, numdays1, numdays2, numdays3, degreeProgram);
    }
}

// Objective E-3A
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int daysInCourse[Student::daysSize];
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

// Objective E-3B
void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
            cout << studentID << " removed." << endl;
        }
    }
    if (found == false)
    {
        cout << studentID << " not found." << endl;
    }
}

// Objective E-3C
void Roster::printAll()
{
    for (int i = 0; i <= this->lastIndex; i++)
        (this->classRosterArray)[i]->printStudent();
}

// Objective E-3D
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i < classSize; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            int avgNumDays = 0;
            avgNumDays = (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3;
            cout << "The average days per course for " << studentID << ": " << avgNumDays << endl;
        }
    }
}

// Objective E-3E
void Roster::printInvalidEmails()
{
    for (int i = 0; i < classSize; i++)
    {
        string emailAddress = (*classRosterArray[i]).getEmailAddress();
        // email address regex pattern
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        if (!regex_match(emailAddress, pattern))
        {
            cout << emailAddress << endl;
        }
    }
}

// Objective E-3F
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    for (int i = 0; i < classSize; i++)
    {

        if ((classRosterArray[i]->getDegreeProgram()) == degreeProgram)
        {
            classRosterArray[i]->printStudent();
        }
    }
}

// Objective F-5
Roster::~Roster(void)
{
    for (int i = 0; i < classSize; i++)
    {
        delete classRosterArray[i];
    }
    delete classRosterArray;
}