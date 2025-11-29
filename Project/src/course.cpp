#include "course.hpp"
#include "models.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

Course getCourse(const std::string &id) {
    string line;
    ifstream courses("/home/baselash/Programming-Language-1-Course/Project/"
                     "data/courses.txt");

    while (getline(courses, line)) {
        Course course = parseLineToCourse(line);
        if (course.course_id == id) {
            return course;
        } else {
            continue;
        }
    }
    Course non_course;
    non_course.course_id = "000";
    return non_course;
}

void addCourse(const Course &course) {
    string line;
    bool found = false;
    ifstream check("/home/baselash/Programming-Language-1-Course/Project/data/"
                   "courses.txt");
    ofstream courses(
        "/home/baselash/Programming-Language-1-Course/Project/data/courses.txt",
        ios::app);

    while (getline(check, line)) {
        Course file_course = parseLineToCourse(line);
        if (file_course.course_id == course.course_id) {
            cout << "Can't add this course. This ID has been taken before. "
                 << endl;
            found = true;
        }
    }
    if (!found)
        appendCourseToFile(courses, course);
    else
        cout << "Can't Add This Course. :/" << endl;
}

void modifyCourse(const string &id) {
    ifstream courses("/home/baselash/Programming-Language-1-Course/Project/"
                     "data/courses.txt");
    ofstream temp(
        "/home/baselash/Programming-Language-1-Course/Project/data/temp.txt");
    bool found = false;
    string line;
    while (getline(courses, line)) {
        Course c = parseLineToCourse(line);
        if (c.course_id == id) {
            found = true;
            getCourseInput(c);
            appendCourseToFile(temp, c);
        } else {
            temp << line << "\n";
        }
    }
    courses.close();
    temp.close();

    if (found) {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "courses.txt");
        rename("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt",
               "/home/baselash/Programming-Language-1-Course/Project/data/"
               "courses.txt");
    } else {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt");
        cout << "Course not found. :/" << endl;
    }
}
void deleteCourse(const string &id) {
    ifstream courses("/home/baselash/Programming-Language-1-Course/Project/"
                     "data/courses.txt");
    ofstream temp(
        "/home/baselash/Programming-Language-1-Course/Project/data/temp.txt");
    bool found = false;
    string line;
    while (getline(courses, line)) {
        Course course = parseLineToCourse(line);
        if (course.course_id == id)
            found = true;
        else
            temp << line << "\n";
    }
    courses.close();
    temp.close();

    if (found) {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "courses.txt");
        rename("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt",
               "/home/baselash/Programming-Language-1-Course/Project/data/"
               "courses.txt");
        cout << "The Course Has Been Deleted Successfully. :)";
    } else {
        remove("/home/baselash/Programming-Language-1-Course/Project/data/"
               "temp.txt");
        cout << "Course not found. :/" << endl;
    }
}

Course parseLineToCourse(const string &line) {
    vector<string> parsed_line = split(line, '|');
    Course course;
    course.course_id = parsed_line[0];
    course.course_name = parsed_line[1];
    try {
        course.course_credit = stoi(parsed_line[2]);
    } catch (const invalid_argument &e) {
    } catch (const out_of_range &e) {
    }
    course.course_property = parsed_line[3];
    return course;
}

void setCourseCompulsory(string &course_property) {
    string user_input, lower_user_input;
    do {
        cout << "Is The Course Compulsory (yes/no): ";
        getline(cin, user_input);
        lower_user_input = wordToLower(user_input);
        if (lower_user_input == "yes") {
            course_property = "Compulsory";
            break;
        } else if (lower_user_input == "no") {
            course_property = "Optional";
            break;
        } else {
            continue;
        }
    } while (true);
}

void getCourseInput(Course &course) {
    cout << "Enter Course ID: ";
    getline(cin, course.course_id);
    cout << "Enter Course Name: ";
    getline(cin, course.course_name);
    int course_credit = getInteger("Enter the Course Credit: ");
    course.course_credit = course_credit;
    setCourseCompulsory(course.course_property);
}

void appendCourseToFile(ofstream &file, const Course &c) {
    file << c.course_id << "|" << c.course_name << "|" << c.course_credit << "|"
         << c.course_property << "\n";
}
