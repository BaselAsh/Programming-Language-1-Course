#ifndef INFO_HPP
#define INFO_HPP

#include "models.hpp"
#include <fstream>
#include <string>

void registerStudentToCourse(const Student &student, const Course &course);
void displayGraduates();
Info parseLineToInfo(const std::string &line);
void appendInfoToFile(std::ofstream &file, const Info &info);
void enterStudentScore(const std::string &course_id,
                       const std::string &student_id, const int &score);
void getStudentCredit(const std::string &id);
void isFailed(const std::string &student_id, const std::string &course_id);

#endif // !INFO_HPP
