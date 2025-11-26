#include "course.hpp"
#include "models.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void addCourse(const Course &course) {
    string line;
    ifstream check("/home/baselash/Programming-Language-1-Course/Project/data/"
                   "courses.txt");

    while (getline(check, line)) {
        Course file_course = parseLineToCourse(line);
        if (file_course.course_id = course.course_id) {
            cout << "Can't add this course. This ID has been taken before.";
            return;
        }
    }
}
void modifyCourse() {}
void deleteCourse() {}
