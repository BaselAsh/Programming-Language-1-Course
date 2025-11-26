#include <iostream>
using namespace std;

void deleteAnElement(int arr[], int size) {
    int delete_num;
    for (int i = 0; i < 5; i++) {
        cout << "Enter the number at index " << i << " : ";
        cin >> arr[i];
    }
    cout << "Enter the number you want to delete: ";
    cin >> delete_num;
    // delete_num = 5
    // arr = {1, 2, 3, 4, 5}
    for (int i = 0; i < 5; i++) {
        if (arr[i] == delete_num)
            continue;
        cout << arr[i] << endl;
    }
}

int main() {
    int arr[5];
    deleteAnElement(arr, 5);
    return 0;
}
