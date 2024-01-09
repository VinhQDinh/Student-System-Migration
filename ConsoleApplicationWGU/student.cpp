#include <iostream>
#include <string> 
#include "student.h"

Student::Student() {}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse = daysInCourse;
    this->degreeProgram = degreeProgram;
}

Student::~Student() {
    delete[] daysInCourse;
}

std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysInCourse() const {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

void Student::setStudentID(std::string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int* daysInCourse) {
    this->daysInCourse = daysInCourse;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() const {
    std::cout << "Student ID: " << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";
    std::cout << "Degree Program: ";
    switch (degreeProgram) {
    case SECURITY:
        std::cout << "Security";
        break;
    case NETWORK:
        std::cout << "Network";
        break;
    case SOFTWARE:
        std::cout << "Software";
        break;
    }
    std::cout << std::endl;
}
