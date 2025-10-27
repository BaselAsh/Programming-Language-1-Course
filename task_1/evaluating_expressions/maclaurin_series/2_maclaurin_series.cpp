#include <cmath>
#include <iostream>
using namespace std;

long double factorial(int x)
{
    long double final_factorial = 1.0;
    for (; x > 1; x--)
    {
        final_factorial *= x;
    }
    return final_factorial;
}

int main()
{
    double x;
    long double sum_of_terms = 0.0;
    cout << "Enter the value of x: ";
    cin >> x;

    for (int i = 1; i <= 100; i++)
    {
        double exponent = 2.0 * i;
        long double current_term = pow(x, exponent) / factorial(exponent);
        if (i % 2 == 0)
            sum_of_terms -= current_term;
        else
            sum_of_terms += current_term;
    }

    cout << "The sum is " << sum_of_terms << endl;

    return 0;
}
