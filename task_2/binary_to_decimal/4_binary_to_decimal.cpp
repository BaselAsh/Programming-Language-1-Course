#include <cmath>
#include <iostream>
using namespace std;

int to_decimal(int x)
{
    int counter = 0;
    for (int i = 0; x > 0; i++)
    {
        int last_digit = x % 10;
        if (last_digit > 1 || last_digit < 0)
            return -1;
        else
            counter += (last_digit)*pow(2, i);
        x /= 10;
    }
    return counter;
}

int main()
{
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;
    int final_number = to_decimal(user_input);
    if (final_number == -1)
        cout << "Please enter a binary number." << endl;
    else
        cout << user_input << " In binary = " << final_number << " In decimal." << endl;
    return 0;
}
