#include <iostream>
using namespace std;

int findLargest(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    
    int largest = findLargest(arr, size - 1);
    
    if (arr[size - 1] > largest) {
        return arr[size - 1];
    } else {
        return largest;
    }
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = findLargest(arr, n);
    cout << "The largest number in the array is: " << largest << endl;

    return 0;
}
