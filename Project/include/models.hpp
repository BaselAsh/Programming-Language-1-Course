#ifndef MODELS_HPP
#define MODELS_HPP

#include <string>

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
    std::string student_id;
    std::string course_id;
    double score;
};

#endif
