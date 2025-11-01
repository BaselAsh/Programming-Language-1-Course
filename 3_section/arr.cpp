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
        cout << "Enter the index " << i << " : ";
        cin >> user_input[i];
    }

    int counter = 0;
    for (int i = 0; i < size_of_array; i++)
    {
        counter += user_input[i];
    }

    cout << "the sum is " << counter << endl;

    delete[] user_input;
    return 0;
}
