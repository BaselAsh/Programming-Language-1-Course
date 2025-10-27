#include <cmath>
#include <iostream>
using namespace std;

int count_digits(int x)
{
    int counter = 0;
    while (x > 0)
    {
        x /= 10;
        counter++;
    }
    return counter;
}

int armstrong(int x)
{
    int armstrong_number = x;
    int number_of_digits = count_digits(x);
    while (x > 0)
    {
        armstrong_number -= pow(x % 10, number_of_digits);
        x /= 10;
    }
    if (armstrong_number == 0)
        return true;
    else
        return false;
}

int *get_array(int size)
{
    int *user_inputs = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> user_inputs[i];
    }
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    return user_inputs;
}

int main()
{
    int size;
    cout << "What is the size of the array: ";
    cin >> size;
    int *user_numbers = get_array(size);
    for (int i = 0; i < size; i++)
    {
        int number = user_numbers[i];
        if (number < 0)
            continue;
        else if (armstrong(number))
            cout << number << " Is an armstrong number." << endl;
        else
            continue;
    }
    delete[] user_numbers;
    return 0;
}
