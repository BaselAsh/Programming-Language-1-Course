#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "models.hpp"
#include <string>

Student getStudent(const std::string &id);
void addStudent(const Student &student);
void modifyStudent(const std::string &id);
void deleteStudent(const std::string &id);

Student parseLineToStudent(const std::string &line);
void getStudentInput(Student &student);
void appendStudentToFile(std::ofstream &file, const Student &s);
#endif // !STUDENT_H
