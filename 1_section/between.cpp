#include <iostream>
using namespace std;

void sum_in_between(int x, int y)
{

    long i = 0;
    if (x > y)
    {
        y++;
        for (; y < x; y++)
        {
            i += y;
        }
        cout << "the sum of the numbers in between the numbers is " << i << endl;
    }
    else if (x < y)
    {
        x++;
        for (; x < y; x++)
        {
            i += x;
        }
        cout << "the sum of the numbers in between the numbers is " << i << endl;
    }
    else
        cout << "there is no integer number in between the same number" << endl;
}

int main()
{
    int a, b;
    cout << "Enter x :";
    cin >> a;
    cout << "Enter y :";
    cin >> b;

    sum_in_between(a, b);
    return 0;
}
