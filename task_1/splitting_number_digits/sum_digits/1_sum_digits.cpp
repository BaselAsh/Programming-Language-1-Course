#include <iostream>
using namespace std;

int main()
{
    long user_input;
    long digits_sum = 0;
    cout << "Enter a number: ";
    cin >> user_input;

    while (user_input > 0)
    {
        digits_sum += user_input % 10;
        user_input /= 10;
    }

    cout << "The sum of the digits is " << digits_sum << endl;
    return 0;
}
