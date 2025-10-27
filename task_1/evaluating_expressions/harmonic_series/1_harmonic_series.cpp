#include <iostream>
using namespace std;

int main()
{
    long number_of_terms;
    double sum = 1;
    cout << "Enter the number of terms: ";
    cin >> number_of_terms;

    for (int i = 2; i <= number_of_terms; i++)
    {
        sum += 1.0 / i;
    }
    cout << "The sum is " << sum << endl;
    return 0;
}
