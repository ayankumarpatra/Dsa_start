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
    GreaterArray[Array_size-i-1]=-1;
    st.push(arr[Array_size-i]);
    for(i=Array_size-2;i>=0;i--){
       //step 1 . pop all the elements smaller than arr[i]
       while (st.size()>0 && st.top()<=arr[i])
       {
       st.pop();
       }
       // step 2 . mark the ans in next greater element array 
       //1. if size 0 , meeans all em removed , put -1 in that place 
       if(st.size()==0) GreaterArray[i]=-1;
       //2. if size not 0 , means the remaining element is greater than the current element 
       else GreaterArray[i]=st.top();
       //step 3. push the current element in stack;
       st.push(arr[i]);

       /*
       means 2 thing to remember 
       1. you have to travarse the array in reverse order
       2. main operations are 1. pop till any greater element found
                              2. if stack size still not 0 , put that top ans in the greater array 
                              else put -1 in that greater array place 
                              3. push only the current element in the stack        
       */
        
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