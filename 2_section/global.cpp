#include <iostream>
using namespace std;
int x = 0;

void counter()
{
    static int y = 0;
    y++;
    cout << "counter= " << y << endl;
    x++;
    cout << "x= " << x << endl;
}

int main()
{
    counter();
    counter();
    counter();
    return 0;
}
