#include <iostream>
using namespace std;

int main()
{
    int terms;
    cout << "Enter the number of terms: ";
    cin >> terms;
    long t1 = 0, t2 = 1;
    if (terms == 1)
        cout << "fibonacci: 0" << endl;
    else if (terms == 1)
        cout << "fibonacci: 0, 1" << endl;
    else if (terms > 1)
        cout << "fibonacci: 0, 1";

    for (int i = 3; i <= terms; i++)
    {
        long current_term = t1 + t2;
        t1 = t2;
        t2 = current_term;
        cout << ", " << current_term;
    }
    cout << endl;
    return 0;
}
