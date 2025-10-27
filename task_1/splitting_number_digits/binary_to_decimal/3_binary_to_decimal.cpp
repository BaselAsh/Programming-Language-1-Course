#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long user_input;
    long decimal_number = 0;
    long i = 0;
    cout << "Enter the binary: ";
    cin >> user_input;

    while (user_input > 0)
    {
        decimal_number += user_input % 10 * pow(2, i);
        user_input /= 10;
        i++;
    }
    cout << "The decimal equivalent is " << decimal_number << endl;

    return 0;
}
