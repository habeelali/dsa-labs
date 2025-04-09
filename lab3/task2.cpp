#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    cout << "Enter " << SIZE << " integers:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int first = -100000, second = -100000, third = -100000;

    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }

    cout << "\nLargest 1 = " << first << endl;
    cout << "Largest 2 = " << second << endl;
    cout << "Largest 3 = " << third << endl;

    return 0;
}
