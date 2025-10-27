#include <iostream>
using namespace std;

void sum_avg(float x, float y, float z)
{
    float the_sum = x + y + z;
    cout << x << " + " << y << " + " << z << " = " << x + y + z << endl;
    cout << "The average is " << the_sum / 3.0 << endl;
}

int main()
{
    int a, b, c;
    cout << "Enter x: ";
    cin >> a;
    cout << "Enter y: ";
    cin >> b;
    cout << "Enter z: ";
    cin >> c;
    sum_avg(a, b, c);

    return 0;
}
