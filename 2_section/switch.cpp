#include <iostream>
using namespace std;

void switching_values(int &a, int &b)
{
    int *temp;
    temp = &b;
    b = a;
}

int main()
{

    return 0;
}
