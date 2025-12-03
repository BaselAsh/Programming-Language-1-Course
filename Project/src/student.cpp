#include "student.hpp"
#include "models.hpp"
#include "utils.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

Student getStudent(const string &id) {
    string line;
    ifstream students("/home/baselash/Programming-Language-1-Course/Project/"
                      "data/students.txt");

    while (getline(students, line)) {
        Student student = parseLineToStudent(line);
        if (student.student_id == id) {
            return student;
        } else {
            continue;
        }
    }
    Student non_student;
    non_student.student_id = "000";
    students.close();
    return non_student;
}

void addStudent(const Student &student) {
    string line;
    ifstream check("/home/baselash/Programming-Language-1-Course/Project/data/"
                   "students.txt");

    while (getline(check, line)) {
        Student file_student = parseLineToStudent(line);
        if (file_student.student_id == student.student_id) {
            cout << "Can't add this student. This ID has been taken." << endl;
            return;
        }
    }

    ofstream students("/home/baselash/Programming-Language-1-Course/Project/"
                      "data/students.txt",
                      ios::app);
    if (students.is_open()) {
        appendStudentToFile(students, student);
        students.close();
        cout << "Student has been added successfully!!!" << endl;
    }
    check.close();
    students.close();
}

void modifyStudent(const string &id) {
    ifstream students("/home/baselash/Programming-Language-1-Course/Project/"
                      "data/students.txt");
    ofstream temp(
        "/home/baselash/Programming-Language-1-Course/Project/data/temp.txt");
    bool found = false;
    string line;
    while (getline(students, line)) {
        Student s = parseLineToStudent(line);
        if (s.student_id == id) {
            found = true;
            getStudentInput(s);
            appendStudentToFile(temp, s);
        } else {
            temp << line << "\n";
        }
    }
    students.close();
    temp.close();

    if (found) {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "students.txt");
        rename("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt",
               "/home/baselash/Programming-Language-1-Course/Project/data/"
               "students.txt");
    } else {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt");
        cout << "Student not found. :/" << endl;
    }
}

void deleteStudent(const string &id) {
    ifstream students("/home/baselash/Programming-Language-1-Course/Project/"
                      "data/students.txt");
    ofstream temp(
        "/home/baselash/Programming-Language-1-Course/Project/data/temp.txt");
    bool found = false;
    string line;
    while (getline(students, line)) {
        Student s = parseLineToStudent(line);
        if (s.student_id == id)
            found = true;
        else
            temp << line << "\n";
    }
    students.close();
    temp.close();

    if (found) {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "students.txt");
        rename("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt",
               "/home/baselash/Programming-Language-1-Course/Project/data/"
               "students.txt");
        cout << "The Student Has Been Deleted Successfully. :)";
    } else {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt");
        cout << "Student not found. :/" << endl;
    }
}

Student parseLineToStudent(const string &line) {
    vector<string> parsed_line = split(line, '|');
    Student s;
    s.student_id = parsed_line[0];
    s.name = parsed_line[1];
    s.sex = parsed_line[2];
    s.age = parsed_line[3];
    s.institution = parsed_line[4];
    s.major = parsed_line[5];
    return s;
}

void getStudentInput(Student &student) {
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Sex: ";
    getline(cin, student.sex);
    cout << "Enter Age: ";
    getline(cin, student.age);
    cout << "Enter Institution: ";
    getline(cin, student.institution);
    cout << "Enter Major: ";
    getline(cin, student.major);
}
void appendStudentToFile(ofstream &file, const Student &s) {
    file << s.student_id << "|" << s.name << "|" << s.sex << "|" << s.age << "|"
         << s.institution << "|" << s.major << "\n";
}
