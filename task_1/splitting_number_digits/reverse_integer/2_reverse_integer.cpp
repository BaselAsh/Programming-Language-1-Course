#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long user_input;
    cout << "Enter a number: ";
    cin >> user_input;
    cout << "The reversed integer is ";
    while (user_input > 0)
    {
        cout << user_input % 10;
        user_input /= 10;
    }
    cout << endl;

    return 0;
}
