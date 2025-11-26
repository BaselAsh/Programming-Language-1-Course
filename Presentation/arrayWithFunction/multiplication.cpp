#include <iostream>
using namespace std;

void multiplication(int arr[], int size) {
    int counter = 1;
    for (int i = 0; i < size; i++)
        counter *= arr[i];
    cout << "The result is " << counter << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    multiplication(arr, 5);
    return 0;
}
