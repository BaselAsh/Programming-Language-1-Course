#ifndef UTILS_HPP
#define UTILS_HPP

#include "models.hpp"
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, char delimiter);
void appendToFile(std::ofstream &file, const Student &s);
Student parseLineToStudent(const std::string &line);
Course parseLineToCourse(const std::string &line);
void getStudentInput(Student &student);
int getInteger(const std::string prompt);
int getTheOperation();
std::string getID();

#endif // !UTILS_H
