#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest =i;
    int left=2*i+1, right=2*i+2;

    if (left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if (right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if (largest!=i){
        swap(arr[0],arr[i]);
        heapify(arr,n,i);
    }

}

void heapsort(int arr[], int n){
    // building max heap

    for (int i=n/2-1 ; i>=0 ; i--){
        heapify (arr,n,i);
    }
    for (int i=n-1 ; i>0 ; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

    
}

int main()
{
    int n=5;

    int arr[]={24,575,43,344,11};


    heapsort(arr,n);

    cout<<"Sorted Array : ";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}