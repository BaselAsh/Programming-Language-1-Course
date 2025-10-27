#include <iostream>
using namespace std;

int main()
{
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;
    if (user_input <= 1)
        cout << "This number is not prime " << endl;

    for (int i = 2; i < user_input; i++)
    {
        if (user_input % i == 0)
        {
            cout << "This number is not prime " << endl;
            return 0;
        }
    }
    cout << "This number is prime" << endl;
    return 0;
}
