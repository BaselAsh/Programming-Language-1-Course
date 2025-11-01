#include <iostream>
using namespace std;
template <class d> d average_number(d a, d b, d c)
{
    return (a + b + c) / 3;
}

int main()
{
    double x, y, z;
    cout << "Enter x, y, z : ";
    cin >> x >> y >> z;
    cout << "The average is " << average_number(x, y, z) << endl;
    return 0;
}
