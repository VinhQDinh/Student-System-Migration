#pragma once
#include <string>
#include <vector>
#include "student.h"

class Roster {
public:
    Roster();
    ~Roster();

    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    const std::vector<Student*>& getRoster() const; 

private:
    std::vector<Student*> classRosterArray;
    bool isEmailValid(const std::string& email) const;
};
