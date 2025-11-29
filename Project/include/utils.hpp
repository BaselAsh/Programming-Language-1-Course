#ifndef UTILS_HPP
#define UTILS_HPP

#include "models.hpp"
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, char delimiter);
void appendStudentToFile(std::ofstream &file, const Student &s);
int getInteger(const std::string prompt);
int getTheOperation();
std::string wordToLower(const std::string &word);
std::string getID(const std::string &prompt);

#endif // !UTILS_H
