#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


int partition (int arr[],int lower_bound, int Upper_bound){
    int pivot=arr[0];
    int start=lower_bound,end=Upper_bound;

    while (start<end){
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
    swap(arr[lower_bound],arr[end]);
    return end;
}


void quicksort(int arr[],int lower_bound,int upper_bound){
    if (lower_bound<upper_bound){
        int pos=partition(arr,lower_bound,upper_bound);
        quicksort(arr,lower_bound,pos-1);
        quicksort(arr,pos+1,upper_bound);
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