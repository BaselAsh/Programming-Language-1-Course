#include <iostream>
using namespace std;

int main()
{
    long i = 0;
    double largest;
    double smallest;
    double user_input;
    while (true)
    {
        cout << "Enter a number: ";
        cin >> user_input;
        if (user_input == -99)
        {
            if (i > 0)
            {
                cout << "The smallest number is " << smallest << endl;
                cout << "The largest number is " << largest << endl;
                return 0;
            }
            else
            {
                cout << "There was no number entered." << endl;
                return 0;
            }
        }

        if (i == 0)
        {
            largest = smallest = user_input;
        }
        else
        {
            if (user_input > largest)
                largest = user_input;
            else if (user_input < smallest)
                smallest = user_input;
        }
        i++;
    }
}
