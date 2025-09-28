// fill array with next greater element , if not found , fill -1
/*
eg if given array 9 1 5 2 3 4 5

o/p = -1 5 -1 3 4 5 -1 

*/

#include<iostream>
#include<stack>
using namespace std ;

void FillWithGreaterElements (int arr[] , int Array_size){
    stack <int> st;
    int GreaterArray[Array_size],i=0;
    GreaterArray[Array_size-i]=-1;
    st.push(arr[Array_size-i]);
    for(i=1;i<Array_size;i++){
        GreaterArray[Array_size-i]=-1;
        
    }
    
}

int main (){
    int Array_size;
    cout<<"Enter expected number of elements : ";
    cin>>Array_size;
    int arr [Array_size];
    for (int i=1;i<=Array_size;i++){
        cout<<"\nEnter elemnt "<<i<<" : ";
        cin>>arr[i];
    }

    FillWithGreaterElements(arr,Array_size);
    return 0;
}