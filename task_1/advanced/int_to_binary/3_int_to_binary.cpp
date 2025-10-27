#include <iostream>
#include <string>
using namespace std;

int main()
{
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;

    string binary_string = "";

    cout << user_input;
    while (user_input > 0)
    {
        binary_string = to_string(user_input % 2) + binary_string;
        user_input /= 2;
    }
    cout << " binary is " << binary_string << endl;

    return 0;
}
