#include <iostream>
using namespace std;

void findElement(int arr[], int size, int element) {
    bool found = 0;
    int index;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            found = 1;
            index = i;
        }
    }
    if (found)
        cout << "The element was found at index " << index << endl;
    else
        cout << "The element was not found." << endl;
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    findElement(arr, 5, 2);
    return 0;
}
