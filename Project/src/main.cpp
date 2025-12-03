#include "course.hpp"
#include "info.hpp"
#include "models.hpp"
#include "student.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int user_input = getTheOperation();
    switch (user_input) {
    case 1: {
        // Display Student Information
        string targetID = getID("Enter Student ID: ");
        Student student = getStudent(targetID);
        if (student.student_id != "000") {
            cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
                    "+=+=+=+=+="
                    "+=+=+"
                    "=+=+=+=+=+=+=+=+";
            cout << "ID: " << student.student_id << endl;
            cout << "Name: " << student.name << endl;
            cout << "Sex: " << student.sex << endl;
            cout << "Age: " << student.age << endl;
            cout << "Institution: " << student.institution << endl;
            cout << "Major: " << student.major << endl;
            cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
                    "+=+=+=+=+="
                    "+=+=+"
                    "=+=+=+=+=+=+=+=+";
        } else {
            cout << "Student not found. :/" << endl;
        }
        break;
    }
    case 2: {
        // Add Student
        Student new_student;
        cout << "Enter the Student info. " << endl;
        cout << "Enter ID: ";
        getline(cin, new_student.student_id);
        getStudentInput(new_student);
        addStudent(new_student);
        break;
    }
    case 3: {
        // Modify Student
        string targetID = getID("Enter Student ID: ");
        modifyStudent(targetID);
        break;
    }
    case 4: {
        // Delete Student
        string targetID = getID("Enter Student ID: ");
        deleteStudent(targetID);
        break;
    }
    case 5: {
        // Display Course Information
        string targetID = getID("Enter Course ID: ");
        Course course = getCourse(targetID);
        if (course.course_id != "000") {

            cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
                    "+=+=+=+=+="
                    "+=+=+"
                    "=+=+=+=+=+=+=+=+";
            cout << "ID: " << course.course_id << endl;
            cout << "Name: " << course.course_name << endl;
            cout << "Credit: " << course.course_credit << endl;
            cout << "Property: " << course.course_property << endl;
            cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
                    "+=+=+=+=+="
                    "+=+=+"
                    "=+=+=+=+=+=+=+=+";
        } else {
            cout << "Course Not Found. :/ " << endl;
        }
        break;
    }
    case 6: {
        // Add Course
        Course course;
        getCourseInput(course);
        addCourse(course);
        break;
    }
    case 7: {
        // Modify Course
        string targetID = getID("Enter Course ID: ");
        modifyCourse(targetID);
        break;
    }

    case 8: {
        // Delete Course
        string targetID = getID("Enter Course ID: ");
        deleteCourse(targetID);
        break;
    }
    case 9: {
        // Enroll Student
        string targetStudentID = getID("Enter Student ID: ");
        string targetCourseID = getID("Enter Course ID: ");
        Student student = getStudent(targetStudentID);
        Course course = getCourse(targetCourseID);
        if (student.student_id != "000") {
            if (course.course_id != "000")
                registerStudentToCourse(student, course);
            else
                cout << "This Course ID Doesn't Exist. :/";
        } else
            cout << "This Student ID Doesn't Exist. :/";
        break;
    }
    case 10: {
        // Enter A Score For Student.
        string course_id, student_id;
        cout << "Enter The Student ID: ";
        getline(cin, student_id);
        cout << "Enter The Course ID: ";
        getline(cin, course_id);
        int score = getInteger("Enter The Score: ");
        enterStudentScore(course_id, student_id, score);
        break;
    }
    case 11: {
        // Show Graduates.
        displayGraduates();
        break;
    }
        // case 12:
        // case 13:

    default: {
        cout << "Invalid Input. :/";
        break;
    }
    }
    return 0;
}
