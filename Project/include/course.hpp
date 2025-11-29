#ifndef COURSE_HPP
#define COURSE_HPP

#include "models.hpp"
#include <string>

Course getCourse(const std::string &id);
void addCourse(const Course &course);
void modifyCourse(const std::string &id);
void deleteCourse(const std::string &id);

Course parseLineToCourse(const std::string &line);
void setCourseCompulsory(std::string &course_property);
void getCourseInput(Course &course);
void appendCourseToFile(std::ofstream &file, const Course &c);
#endif
