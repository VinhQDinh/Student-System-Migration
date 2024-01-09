#include <iostream>
#include <string> 
#include "roster.h"

int main() {
    std::cout << "Course: C867 - Scripting and Programming Applications" << std::endl;
    std::cout << "Language: C++" << std::endl;
    std::cout << "Student ID: 009454302" << std::endl;
    std::cout << "Name: Vinh Dinh" << std::endl;

    Roster classRoster;

    
    classRoster.add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
    classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
    classRoster.add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
    classRoster.add("A5", "Vinh", "Dinh", "Vinh.Dinh@gmail.com", 40, 30, 40, 50, SOFTWARE);

    
    std::cout << "\nAll Students:" << std::endl;
    classRoster.printAll();

    
    std::cout << "\nInvalid Email Addresses:" << std::endl;
    classRoster.printInvalidEmails();

    
    std::cout << "\nAverage Number of Days in Course:" << std::endl;
    for (const Student* student : classRoster.getRoster()) {
        classRoster.printAverageDaysInCourse(student->getStudentID());
    }

    
    std::cout << "\nStudents in the Software program:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    
    std::cout << "\nRemoving student with ID A3:" << std::endl;
    classRoster.remove("A3");

    

    classRoster.printAll();

    
    std::cout << "\nRemoving student with ID A3:" << std::endl;
    classRoster.remove("A3");

    return 0;
}
