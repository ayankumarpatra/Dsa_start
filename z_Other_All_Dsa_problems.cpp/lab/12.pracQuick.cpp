#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

int partition(int arr[], int lowerbound, int upperbound){
    int pivot=arr[lowerbound];

    int start=lowerbound,end=upperbound;

    while (start<end)
    {
        while (arr[start]<=pivot)
        {
            start++;
        }
        while (arr[end]>pivot)
        {
            end--;
        }
        
        if (start<end){
            swap(arr[start],arr[end]);
        }
    }

    swap(arr[lowerbound],arr[end]);

    return end;

}

void quicksort(int arr[], int low , int high){
    if (low<high){
        int pos=partition(arr,low,high);
        quicksort(arr,low,pos-1);
        quicksort(arr,pos+1,high);
    }
}


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
    cout << "\nElements Are :\n";
    for(int i = 0; i < n; i++) {
        cout<< arr[i]<<" ";
    }
    
    quicksort(arr,0,n-1);
    
    cout << "\nSorted Elements Are :\n";
    for(int i = 0; i < n; i++) {
        cout<< arr[i]<<" ";
    }
        
    return 0;
}