#include <iostream>
using namespace std;

void addition(int arr[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++)
        counter += arr[i];
    cout << "The sum is " << counter << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    addition(arr, 5);
    return 0;
}
