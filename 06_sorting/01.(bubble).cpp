#include<iostream>
#include<stack>
#include<vector>

using namespace std ;




int main (){
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Taking input
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Bubble Sort (Non-Optimized)
    for(int i = 0; i < n - 1; i++) {          // Outer loop for passes
        for(int j = 0; j < n - 1; j++) {      // Inner loop for comparison
            if(arr[j] > arr[j + 1]) {         // Swap if left > right
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Optimized Bubble Sort
    for(int i = 0; i < n - 1; i++) {          // Outer loop for passes
        bool swapped = false;                // To check if swap happens

        for(int j = 0; j < n - i - 1; j++) { // Last i elements already sorted
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;              // Mark swap happened
            }
        }

        // If no swapping happened, array is already sorted
        if(swapped == false) {
            break;
        }
    }
       
    return 0;
}