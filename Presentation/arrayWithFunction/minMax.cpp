#include <iostream>
using namespace std;

void minMax(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    minMax(arr, 5);
    return 0;
}
