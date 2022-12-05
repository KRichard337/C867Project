#ifndef roster_h
#define roster_h

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

class Roster
{
private:
    int classSize;
    int lastIndex;

public:
    Student **classRosterArray;
    Roster();
    Roster(int classSize);
    ~Roster(void);

    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parse(string row);
    void printEmails();
};
#endif