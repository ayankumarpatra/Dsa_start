#include<iostream>
#include<stack>
using namespace std ;

void FillByPreviousGreaterElements(int MainArr[],int PrevGreaterArr[],int ArrSize){
    int i=0;
    stack <int> st;
    PrevGreaterArr[i]=-1;
    st.push(MainArr[i]);
    for(i=1;i<ArrSize;i++){
        while(st.size()>0 && MainArr[i]>=st.top()){
        st.pop();
    }
    if(st.size()==0){
        PrevGreaterArr[i]=-1;
    }
    else {
        PrevGreaterArr[i]=st.top();
    }
    st.push(MainArr[i]);
     
}

cout<<"Array filled with greater elements\n";
}

void ArrPrinter(int Arr[],int ArrSize){
    if(ArrSize==0){
        cout<<"Invalid Array Size to print\n";
        return;
    }
    for(int i=0;i<ArrSize;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

int main (){
    int ArrSize;
    cout<<"Enter Approx No of elements : ";
    cin>>ArrSize;
    int MainArr[ArrSize],PrevGreaterElement[ArrSize];
    for(int i=0;i<ArrSize;i++){
        cout<<"Enter Element "<<i+1<<" : ";
        cin>>MainArr[i];
    }

    ArrPrinter(MainArr,ArrSize);

    FillByPreviousGreaterElements(MainArr,PrevGreaterElement,ArrSize);

    ArrPrinter(PrevGreaterElement,ArrSize);

    return 0;
}