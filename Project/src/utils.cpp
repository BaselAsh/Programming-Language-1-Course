#include "utils.hpp"
#include "models.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void appendToFile(ofstream &file, const Student &s) {
    file << s.student_id << "|" << s.name << "|" << s.sex << "|" << s.age << "|"
         << s.institution << "|" << s.major << "\n";
}

void getStudentInput(Student &student) {
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Sex: ";
    getline(cin, student.sex);
    cout << "Enter Age: ";
    getline(cin, student.age);
    cout << "Enter Institution: ";
    getline(cin, student.institution);
    cout << "Enter Major: ";
    getline(cin, student.major);
}

Student parseLineToStudent(const string &line) {
    vector<string> parsed_line = split(line, '|');
    Student s;
    s.student_id = parsed_line[0];
    s.name = parsed_line[1];
    s.sex = parsed_line[2];
    s.age = parsed_line[3];
    s.institution = parsed_line[4];
    s.major = parsed_line[5];
    return s;
}

Course parseLineToCourse(const string &line) {
    vector<string> parsed_line = split(line, '|');
    Course c;
    c.course_id = parsed_line[0];
    c.course_name = parsed_line[1];
    c.course_credit = stoi(parsed_line[2]);
    c.course_property = parsed_line[3];
    return c;
}

// Get a number without an error or string
int getInteger(const string prompt) {
    int value;
    string input_line;
    while (true) {
        cout << prompt;
        getline(cin, input_line);
        stringstream ss(input_line);
        // (ss >> value) Saves the user input number in the value variable.
        // (ss >> ws).eof() Checks if there is anything left in the line (string
        // or whitespace)
        if (((ss >> value) && (ss >> ws).eof()) &&
            (value >= 1 && value <= 11)) {
            return value;
        }
        cout << "Invalid input. Please enter a whole number only." << endl;
    }
}

int getTheOperation() {
    int user_input;
    cout << "Welcome!" << endl;
    cout << "What would you like to do." << endl;
    cout << "Type The Number Of The Operation That You Want To Do." << endl;
    cout << "1) Display Student Information." << endl;
    cout << "2) Add Student." << endl;
    cout << "3) Modify Student." << endl;
    cout << "4) Delete Student." << endl;
    cout << "5) Display Course Information." << endl;
    cout << "6) Add Course." << endl;
    cout << "7) Modify Course." << endl;
    cout << "8) Delete Course." << endl;
    cout << "9) Enroll a Student." << endl;
    cout << "10) Show Graduates." << endl;
    cout << "11) Show Failed Students." << endl;
    user_input = getInteger("What Would You Like To Do?: ");
    return user_input;
}

string getID() {
    string targetID;
    cout << "Enter ID: ";
    cin >> targetID;
    cin.ignore();
    return targetID;
}
