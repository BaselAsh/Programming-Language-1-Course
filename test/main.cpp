#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Student {
    std::string student_id;
    std::string name;
    std::string sex;
    std::string age;
    std::string institution;
    std::string major;
};

struct Course {
    std::string course_id;
    std::string course_name;
    int course_credit;
    std::string course_property;
};

struct Info {
    Student student;
    Course course;
    int score = -1;
};

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
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
    return non_student;
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

Info parseLineToInfo(const string &line) {
    vector<string> parsed_line = split(line, '|');
    Info info;
    info.student = getStudent(parsed_line.at(0));
    info.course = getCourse(parsed_line.at(1));
    info.score = stoi(parsed_line.at(2));
    return info;
}

int main() {
    string i;
    ifstream infos("/home/baselash/Programming-Language-1-Course/Project/"
                   "data/info.txt");
    getline(infos, i);
    while (getline(infos, i)) {
        Info info = parseLineToInfo(i);
        cout << "Student Name: " << info.student.name << endl
             << "Course ID: " << info.course.course_id << endl
             << "Score: " << info.score << endl;
    }

    return 0;
}
