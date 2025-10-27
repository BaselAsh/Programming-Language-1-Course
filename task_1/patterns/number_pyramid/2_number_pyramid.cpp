#include <iostream>
using namespace std;

int main()
{
    int height;
    cout << "Enter the pyramid height: ";
    cin >> height;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; j++)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
