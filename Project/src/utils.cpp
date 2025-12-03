#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

vector<string> split(const string &s, const char &delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string wordToLower(const string &word) {
    vector<char> letters;
    vector<char> lower_letters;
    for (char letter : word) {
        if (letter >= 65 && letter <= 90)
            lower_letters.push_back(letter + 32);
        else if (letter >= 97 && letter <= 122)
            lower_letters.push_back(letter);
    }
    string lower_word(lower_letters.begin(), lower_letters.end());
    return lower_word;
}

// Get a number without an error or string
int getInteger(const string prompt) {
    int value;
    string input_line;
    while (true) {
        cout << prompt;
        getline(cin, input_line);
        stringstream ss(input_line);
        if ((ss >> value) && (ss >> ws).eof())
            return value;
        cout << "Invalid input. Please enter a whole number only. " << endl;
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
    cout << "10) Enter A Score For Student." << endl;
    cout << "11) Show Graduates." << endl;
    cout << "12) Show Failed Students In The Exam Of A Course." << endl;
    cout << "13) Show Selected And Obtained Credits Of Student." << endl;
    user_input = getInteger("What Would You Like To Do?: ");
    return user_input;
}

string getID(const string &prompt) {
    string targetID;
    cout << prompt;
    cin >> targetID;
    cin.ignore();
    return targetID;
}
