#include <iostream>
using namespace std;

int main() {

    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    // Outer loop: assume first element is already sorted
    // Start from second element
    for (int i = 1; i < n; i++) {

        int j = i;   // Start comparing from current index

        // Move element backward until it reaches correct position
        while (j >= 1 && arr[j] < arr[j - 1]) {

            // Swap current element with previous element
            swap(arr[j], arr[j - 1]);

            // Move one step backward
            j--;
        }
    }

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}