#include <iostream>
using namespace std;

int main() {
    const int SIZE = 9;
    int arr[SIZE];

    cout << "Enter " << SIZE << " elements:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - 1; ++j) {
            if (arr[j] == 0 && arr[j + 1] != 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nArray after pushing zeros to the end:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
