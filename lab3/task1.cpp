#include <iostream>
using namespace std;

int main() {
    const int SIZE = 20;
    int numbers[SIZE];

    int positiveCount = 0, negativeCount = 0;
    int oddCount = 0, evenCount = 0;
    int zeroCount = 0;
    int maxElement, minElement;

    cout << "Enter 20 integer values:\n";

    for (int i = 0; i < SIZE; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];

        if (i == 0) {
            maxElement = numbers[i];
            minElement = numbers[i];
        }

        if (numbers[i] > 0)
            positiveCount++;
        else if (numbers[i] < 0)
            negativeCount++;
        else
            zeroCount++;

        if (numbers[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;

        if (numbers[i] > maxElement)
            maxElement = numbers[i];
        if (numbers[i] < minElement)
            minElement = numbers[i];
    }

    cout << "\nResults:\n";
    cout << "a. Count of positive values: " << positiveCount << endl;
    cout << "b. Count of negative values: " << negativeCount << endl;
    cout << "c. Count of odd values: " << oddCount << endl;
    cout << "d. Count of even values: " << evenCount << endl;
    cout << "e. Count of zero values: " << zeroCount << endl;
    cout << "f. Largest element: " << maxElement << endl;
    cout << "g. Smallest element: " << minElement << endl;

    return 0;
}
