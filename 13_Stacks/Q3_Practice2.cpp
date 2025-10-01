#include<iostream>
#include<stack>
using namespace std ;

void GreaterArrayFiller(int MainArr[],int GreaterArr[],int ArraySize){
    int i=0;
    GreaterArr[ArraySize-i-1]=-1;
    stack <int> st;
    st.push(MainArr[ArraySize-i-1]);
    for(i=ArraySize-2;i>=0;i--){
        while (st.size()>0 && MainArr[i]>=st.top())
        {
        st.pop();
        }

        if(st.size()==0){
            GreaterArr[i]=-1;
        }

        else {
            GreaterArr[i]=st.top();
        }
        st.push(MainArr[i]);
    }
    cout<<"Array Succesfully filled with greater elements \n";

}

void ArrayPrinter(int Array[],int ArraySize){
    if (ArraySize==0){
        cout<<"Invalid Array to print \n";
        return;
    }
    for (int i=0;i<ArraySize;i++){
        cout<<Array[i]<<" ";
    }
}

int main (){
    int ArraySize;
    cout<<"Enter expected Array size : ";
    cin>>ArraySize;

    int MainArr[ArraySize],GreaterArr[ArraySize];

    for(int i=0;i<ArraySize;i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>MainArr[i];
    }

    ArrayPrinter(MainArr,ArraySize);
    
    GreaterArrayFiller(MainArr,GreaterArr,ArraySize);
    
    ArrayPrinter(GreaterArr,ArraySize);

    return 0;
}