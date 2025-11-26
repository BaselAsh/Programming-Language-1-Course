#include "models.hpp"
#include "student.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
using namespace std;

// void registerStudentToCourse ();
// void inputStudentScore ();
// void displayFailedStudents ();
// void displayGraduatedStudents ();
// void calculateStudentCredits ();

int main() {
    int user_input = getTheOperation();
    switch (user_input) {
    case 1:
        displayStudent("50");
        break;
    case 2: {
        Student new_student;
        cout << "Enter the Student info." << endl;
        cout << "Enter ID: ";
        getline(cin, new_student.student_id);
        getStudentInput(new_student);
        addStudent(new_student);
        break;
    }
    case 3: {
        string targetID;
        cout << "Enter ID to modify: ";
        cin >> targetID;

        modifyStudent(targetID);
        break;
    }
    case 4: {
        string id = getID();
        deleteStudent(id);
        break;
    }
    // case 5:
    // case 6:
    // case 7:
    // case 8:
    // case 9:
    // case 10:
    // case 11:
    default:
        cout << "Invalid Input. :/";
        break;
    }
    return 0;
}
