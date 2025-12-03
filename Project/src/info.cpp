#include "info.hpp"
#include "course.hpp"
#include "models.hpp"
#include "student.hpp"
#include "utils.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void registerStudentToCourse(const Student &student, const Course &course) {
    Info info;
    info.student = student;
    info.course = course;
    ofstream infos(
        "/home/baselash/Programming-Language-1-Course/Project/data/infos.txt",
        ios::app);
    appendInfoToFile(infos, info);
    cout << "The Student Has Been Enrolled Successfully. :)" << endl;
}

void displayGraduates() {
    ifstream students("/home/baselash/Programming-Language-1-Course/Project/"
                      "data/students.txt");
    ifstream infos(
        "/home/baselash/Programming-Language-1-Course/Project/data/infos.txt");
    string infos_header;
    string students_header;
    string students_line;
    string infos_line;
    Student student;
    Info info;
    int complusary_score = 0;
    int optional_score = 0;
    getline(students, students_header);
    getline(infos, infos_header);

    while (getline(students, students_line)) {
        student = parseLineToStudent(students_line);
        while (getline(infos, infos_line)) {
            info = parseLineToInfo(infos_line);
            if ((info.student.student_id == student.student_id) &&
                (info.score >= 50)) {
                if (info.course.course_property == "Compulsory") {
                    complusary_score += info.course.course_credit;
                } else {
                    optional_score += info.course.course_credit;
                }
            }
        }
        if (complusary_score >= 24 &&
            (complusary_score + optional_score) >= 36) {
            cout << student.student_id << ": " << student.name
                 << " Has Graduated Successfully !!! :)" << endl;
        }
        complusary_score = 0;
        optional_score = 0;
        infos.clear();
        infos.seekg(0, ios::beg);
    }
    students.close();
    infos.close();
}

Info parseLineToInfo(const string &line) {
    vector<string> parsed_line = split(line, '|');
    Info info;
    info.student = getStudent(parsed_line.at(0));
    info.course = getCourse(parsed_line.at(1));
    try {
        info.score = stoi(parsed_line.at(2));
    } catch (const invalid_argument &e) {
    } catch (const out_of_range &e) {
    }
    return info;
}

void appendInfoToFile(ofstream &file, const Info &info) {
    file << info.student.student_id << "|" << info.course.course_id << "|"
         << info.score << "\n";
}

void enterStudentScore(const string &course_id, const string &student_id,
                       const int &score) {
    ifstream infos("/home/baselash/Programming-Language-1-Course/Project/"
                   "data/infos.txt");
    ofstream temp(
        "/home/baselash/Programming-Language-1-Course/Project/data/temp.txt");
    bool found = false;
    string line;
    while (getline(infos, line)) {
        Info i = parseLineToInfo(line);
        if (i.student.student_id == student_id &&
            i.course.course_id == course_id) {
            found = true;
            i.score = score;
            appendInfoToFile(temp, i);
        } else {
            temp << line << "\n";
        }
    }
    infos.close();
    temp.close();

    if (found) {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "infos.txt");
        rename("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt",
               "/home/baselash/Programming-Language-1-Course/Project/data/"
               "infos.txt");
    } else {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt");
        cout << "Didn't Find The This Student Enrolled To This Course. :/"
             << endl;
    }
}

bool isFailed(const string &student_id, const string &course_id) {
    ifstream infos(
        "/home/baselash/Programming-Language-1-Course/Project/data/infos.txt");
    string infos_line;
    Info file_info;
    while (getline(infos, infos_line)) {
        file_info = parseLineToInfo(infos_line);
        if (student_id == file_info.student.student_id &&
            course_id == file_info.course.course_id) {
            if (file_info.score >= 60)
                return false;
            else
                return true;
        } else {
            continue;
        }
    }

    return true;
}
