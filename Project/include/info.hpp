#ifndef INFO_HPP
#define INFO_HPP

#include "models.hpp"
#include <fstream>
#include <string>

void registerStudentToCourse(const Student &student, const Course &course);
void displayGraduates();
// void displayFailedStudents();
void calculateStudentCredits();
Info parseLineToInfo(const std::string &line);
void appendInfoToFile(std::ofstream &file, const Info &info);
void enterStudentScore(const std::string &course_id,
                       const std::string &student_id, const int &score);
bool isFailed(const std::string &student_id, const std::string &course_id);

#endif // !INFO_HPP
