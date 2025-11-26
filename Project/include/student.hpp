#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "models.hpp"
#include <string>

void displayStudent(const std::string &id);
void addStudent(const Student &student);
void modifyStudent(const std::string &id);
void deleteStudent(const std::string &id);

#endif // !STUDENT_H
