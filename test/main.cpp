#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string wordToUpper(const string &word) {
    vector<char> letters;
    vector<char> upper_letters;
    for (char letter : word) {
        if (letter >= 97 && letter <= 122)
            upper_letters.push_back(letter - 32);
        else if (letter >= 65 && letter <= 90)
            upper_letters.push_back(letter);
        else
            upper_letters.push_back(letter);
    }
    string lower_word(upper_letters.begin(), upper_letters.end());
    return lower_word;
}

int main() {
    cout << wordToUpper("mt103") << endl;
    return 0;
}
