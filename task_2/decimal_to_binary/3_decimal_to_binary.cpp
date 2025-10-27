#include <iostream>
#include <string>
using namespace std;

string to_binary(int x)
{
    string binary = "";
    while (x > 0)
    {
        binary = to_string(x % 2) + binary;
        x /= 2;
    }
    return binary;
}

int main()
{
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;
    cout << "The binary equivalent of the number " << user_input << " is " << to_binary(user_input) << "." << endl;
    return 0;
}
