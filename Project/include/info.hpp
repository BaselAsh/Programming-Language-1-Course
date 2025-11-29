#ifndef INFO_HPP
#define INFO_HPP

#include "models.hpp"
#include <fstream>
#include <string>

void registerStudentToCourse(const Student &student, const Course &course);
void inputStudentScore(const std::string &student_id,
                       const std::string &course_id);
void displayFailedStudents();
void displayGraduatedStudents();
void calculateStudentCredits();
void appendInfoToFile(std::ofstream &file, const Info &info);
bool isFailed(const std::string &student_id, const std::string &course_id);

#endif // !INFO_HPP
