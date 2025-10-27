#include <iostream>
#include <string>
using namespace std;

string reverse_num(int x)
{
    string reversed = "";
    while (x > 0)
    {
        reversed = to_string(x % 10) + reversed;
        x /= 10;
    }
    return reversed;
}

int main()
{
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;
    cout << "reversed number is " << reverse_num(user_input) << endl;
    return 0;
}
