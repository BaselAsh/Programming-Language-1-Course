#include "student.hpp"
#include "models.hpp"
#include "utils.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

void displayStudent(const string &id) {
    string line;
    ifstream students("/home/baselash/Programming-Language-1-Course/Project/"
                      "data/students.txt");

    while (getline(students, line)) {
        Student student = parseLineToStudent(line);
        if (student.student_id == id) {
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
            cout << "Student Not Found. :/" << endl;
        }
    }
}

void addStudent(const Student &student) {
    string line;
    ifstream check("/home/baselash/Programming-Language-1-Course/Project/data/"
                   "students.txt");

    while (getline(check, line)) {
        Student file_student = parseLineToStudent(line);
        if (file_student.student_id == student.student_id) {
            cout << "Can't add this student. This ID has been taken.";
            return;
        }
    }

    ofstream students("/home/baselash/Programming-Language-1-Course/Project/"
                      "data/students.txt",
                      ios::app);
    if (students.is_open()) {
        appendToFile(students, student);
        students.close();
        cout << "Student has been added successfully!!!" << endl;
    }
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
            appendToFile(temp, s);
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
    } else {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt");
        cout << "Student not found. :/" << endl;
    }
}
