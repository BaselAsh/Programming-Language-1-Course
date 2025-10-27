#include <iostream>
using namespace std;

bool check_prime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
        else
            continue;
    }
    return true;
}

int main()
{
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;

    if (check_prime(user_input))
        cout << user_input << " is a prime number." << endl;
    else
        cout << user_input << " is not a prime number." << endl;

    return 0;
}
