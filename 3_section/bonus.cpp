#include <iostream>
using namespace std;

int main()
{
    int size_of_array;
    cout << "Enter the size of the array: ";
    cin >> size_of_array;
    int *user_input = new int[size_of_array];
    for (int i = 0; i < size_of_array; i++)
    {
        cout << "Enter the number at the index " << i << " : ";
        cin >> user_input[i];
    }
    int new_index;
    int new_number;
    cout << "enter the new number index: ";
    cin >> new_index;

    cout << "enter the new number: ";
    cin >> new_number;
    for (int i = 0; i < size_of_array; i++)
    {
        if (i == new_index)
        {
            cout << new_number;
            cout << user_input[i];
        }
        else
        {
            cout << user_input[i];
        }
    }
    cout << endl;

    delete[] user_input;
    return 0;
}
