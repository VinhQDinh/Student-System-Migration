#include <iostream>
#include <sstream>
#include <string> 
#include "roster.h"

Roster::Roster() {}

Roster::~Roster() {
    for (Student* student : classRosterArray) {
        delete student;
    }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int* daysInCourse = new int[3];
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;

    classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram));
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); ++it) {
        if ((*it)->getStudentID() == studentID) {
            delete* it;
            classRosterArray.erase(it);
            std::cout << "Student with ID " << studentID << " removed." << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll() const {
    for (const Student* student : classRosterArray) {
        student->print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (const Student* student : classRosterArray) {
        if (student->getStudentID() == studentID) {
            int* daysInCourse = student->getDaysInCourse();
            int average = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
            std::cout << "Average number of days in the course for student " << studentID << ": " << average << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() const {
    for (const Student* student : classRosterArray) {
        std::string email = student->getEmailAddress();
        if (!isEmailValid(email)) {
            std::cout << "Invalid email address: " << email << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (const Student* student : classRosterArray) {
        if (student->getDegreeProgram() == degreeProgram) {
            student->print();
        }
    }
}

const std::vector<Student*>& Roster::getRoster() const {
    return classRosterArray;
}

bool Roster::isEmailValid(const std::string& email) const {
    size_t atPos = email.find('@');
    size_t dotPos = email.rfind('.');
    return atPos != std::string::npos && dotPos != std::string::npos && atPos < dotPos;
}
