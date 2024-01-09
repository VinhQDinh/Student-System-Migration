#pragma once
#include <string>
#include "degree.h"

class Student {
public:
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);
    ~Student();

    // Accessors
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    int* getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    // Mutators
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int* daysInCourse);
    void setDegreeProgram(DegreeProgram degreeProgram);

    void print() const;

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int* daysInCourse;
    DegreeProgram degreeProgram;
};
