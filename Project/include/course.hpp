#ifndef COURSE_HPP
#define COURSE_HPP

#include "models.hpp"

void addCourse(const Course &course);
void modifyCourse();
void deleteCourse();

Course parseLineToCourse(const std::string &line);
void setCourseCompulsory(std::string &course_property);
void getCourseInput(Course &course);
void appendCourseToFile(std::ofstream &file, const Course &c);
#endif
