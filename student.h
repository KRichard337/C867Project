#ifndef student_h
#define student_h

#include <iostream>
#include <string>
#include <vector>
#include "degree.h"
using namespace std;

class Student
{
public:
    const static int daysSize = 3;

    // Objective D-2C
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysSize];
    DegreeProgram degreeProgram;

public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int *getDaysInCourse();
    DegreeProgram getDegreeProgram();

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int days1, int days2, int days3);
    void setDegreeProgram(DegreeProgram degreeProgram);
    void printStudent();
};
#endif