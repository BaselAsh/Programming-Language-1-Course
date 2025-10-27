#include <iostream>
using namespace std;

int sum_avg()
{
    int sum;
    int *avg = &sum + 1;
    sum = ((1 + 2 + 3 + 4) / 4);
    return sum;
}

int main()
{
    int sum = sum_avg();
    int *avg = &sum + 1;

    cout << sum << avg << endl;

    return 0;
}
