#include <iostream>
#include <climits>
using namespace std;

int main() {

    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;


// Selection sort 

    // Outer loop: move boundary of sorted and unsorted part
    for (int i = 0; i < n - 1; i++) {

        int min = INT_MAX;   // Assume very large value initially
        int min_idx = -1;    // To store index of minimum element

        // Inner loop: search minimum element from i to n-1
        for (int j = i; j < n; j++) {

            // If current element is smaller than current minimum
            if (arr[j] < min) {
                min = arr[j];      // Update minimum value
                min_idx = j;       // Update index of minimum
            }
        }

        // Swap the found minimum element with first unsorted element
        // min_idx will NEVER remain -1 because first comparison updates it
        swap(arr[i], arr[min_idx]);
    }

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}