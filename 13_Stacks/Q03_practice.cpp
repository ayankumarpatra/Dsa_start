#include<iostream>
#include<stack>

using namespace std ;

void FillArrayWithGreaterElements (int MainArray[] ,int GreaterArray[], int Array_size){
    stack <int> st;
    int i=0;
    st.push(MainArray[Array_size-i-1]);// pushing the last element in the stack, -1 as indexing start by 0
    GreaterArray[Array_size-i-1]=-1;// as traversing from last , so first em is -1 , no greater after this 
    for(i=Array_size-2;i>=0;i--){
        // poping till arr[i] isnt greater than stack element and stack size isnt 0
        while (st.size()>0 && MainArray[i]>=st.top())
        {
            st.pop();
        }
        if(st.size()==0) {GreaterArray[i]=-1;}
        else {
            GreaterArray[i]=st.top();
        }
        
        st.push(MainArray[i]);
    }
    
    cout<<"\nReversed Array filled successfully\n";

}

void ArrayPrinter(int Arr[], int ArrSize){
    if(ArrSize==0){
        cout<<"\nEmpty array given to print\n";
    }
    for (int i=0;i<ArrSize;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<"\nArray succesfully printed \n";
}


int main (){
    

    int Array_Size;
    cout<<"Enter Approximate Array Size : ";
    cin>>Array_Size;
    int arr[Array_Size],GreaterArr[Array_Size];
    for(int i=0;i<Array_Size;i++){
        cout<<"Enter the element "<<i+1<<" : ";
        cin>>arr[i];
    }

    cout<<"Main array is :\n";
    ArrayPrinter(arr,Array_Size);

    FillArrayWithGreaterElements(arr, GreaterArr, Array_Size);

    
    cout<<"After filling greater elements array is :\n";
    ArrayPrinter(GreaterArr,Array_Size);

    return 0;
}