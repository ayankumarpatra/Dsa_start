#include<iostream>
#include<vector>

using namespace std ;

void counting_sort(int arr[], int n){
    // finding max num 

    int maxval=arr[0];

    for (int i=0;i<n;i++){
        if (arr[i]>maxval){
            maxval=arr[i];
        }
    }
    
    int count[maxval+1]={0};// count array
    
    // filling the freq array (count)
    
    for (int i=0;i<n;i++){
        count[arr[i]]++;
    }
    
    // summing freq array up;
    
    for (int i=1;i<=maxval;i++){
        count[i]+=count[i-1];
    }
    
    int result[n];// final result array 
    
    // filling the result vector
    
    for (int i=n-1;i>=0;i--){// starting from right to do stable sorting 
        int currval=arr[i];
        int pos=count[currval]-1;
        result[pos]=currval;
        count[currval]--;
    }
    

    // copying the same result to main arr[]

    for (int i=0;i<n;i++){
        arr[i]=result[i];
    }

    cout<<"\nSort Successful\n";

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

    counting_sort(arr,n);
        
    cout << "\nSorted Elements Are :\n";
    for(int i = 0; i < n; i++) {
        cout<< arr[i]<<" ";
    }
    
    return 0;
}