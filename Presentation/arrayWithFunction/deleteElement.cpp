#include <iostream>
using namespace std;

void deleteElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element)
            continue;
        cout << arr[i] << endl;
    }
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    deleteElement(arr, 5, 3);
    return 0;
}
