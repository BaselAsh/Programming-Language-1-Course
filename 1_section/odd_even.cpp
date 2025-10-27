#include <iostream>
using namespace std;

void check_even(long x)
{
    if (x % 2 == 0)
        cout << "This number is even" << endl;
    else
        cout << "This number is odd" << endl;
}

int main()
{
    long user_input;
    cout << "Enter a number: ";
    cin >> user_input;
    check_even(user_input);
    return 0;
}
