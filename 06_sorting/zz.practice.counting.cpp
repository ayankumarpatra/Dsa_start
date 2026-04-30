#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

void countingsort(int arr[],int n){

    // finding the max val from the arr
    int maxval=arr[0];

    for(int i=0;i<n;i++){
        if(arr[i]>maxval){
            maxval=arr[i];
        }
    }
    
    int count[maxval+1]={0};
    // filling the freq array , count
    
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    // summing up the freq arr

    for (int i=1;i<=maxval;i++){
        count[i]+=count[i-1];
    }

    int result[n];

    // filling up the result vector 

    for (int i=n-1;i>=0;i--){
        int currval=arr[i];
        int pos=count[currval]-1;
        result[pos]=currval;
        count[currval]--;
    }

    // copying to main result

    for (int i=0;i<n;i++){
        arr[i]=result[i];
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
    

    countingsort(arr,n);


    cout << "\nSorted Elements Are :\n";
    for(int i = 0; i < n; i++) {
        cout<< arr[i]<<" ";
    }
    
    return 0;
}