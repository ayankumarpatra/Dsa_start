#include <iostream>
#include <climits>
using namespace std;

void findMaxMin(int arr[], int low, int high, int &maxi, int &mini)
{
    // Only one element
    if (low == high)
    {
        maxi = arr[low];
        mini = arr[low];
        return;
    }

    // Two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            maxi = arr[low];
            mini = arr[high];
        }
        else
        {
            maxi = arr[high];
            mini = arr[low];
        }
        return;
    }

    // Divide
    int mid = (low + high) / 2;

    int max1, min1;
    int max2, min2;

    // Conquer
    findMaxMin(arr, low, mid, max1, min1);
    findMaxMin(arr, mid + 1, high, max2, min2);

    // Combine
    maxi = (max1 > max2) ? max1 : max2;
    mini = (min1 < min2) ? min1 : min2;
}

int main()
{
    int arr[] = {25, 14, 63, 9, 48, 31, 72, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxi, mini;

    findMaxMin(arr, 0, n - 1, maxi, mini);

    cout << "Maximum = " << maxi << endl;
    cout << "Minimum = " << mini << endl;

    return 0;
}