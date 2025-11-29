#include "info.hpp"
#include "course.hpp"
#include "models.hpp"
#include "student.hpp"
#include "utils.hpp"
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
        "/home/baselash/Programming-Language-1-Course/Project/data/info.txt",
        ios::app);
    appendInfoToFile(infos, info);
    cout << "The Student Has Been Enrolled Successfully. :)";
}

Info parseLineToInfo(const string &line) {
    vector<string> parsed_line = split(line, '|');
    Info info;
    info.student = getStudent(parsed_line[0]);
    info.course = getCourse(parsed_line[1]);
    return info;
}

void appendInfoToFile(ofstream &file, const Info &info) {
    file << info.student.student_id << "|" << info.course.course_id << "|"
         << info.course.course_credit << "|" << info.course.course_property
         << "|" << info.score << "\n";
}

bool isFailed(const string &student_id, const string &course_id) {
    ifstream infos(
        "/home/baselash/Programming-Language-1-Course/Project/data/info.txt");
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
