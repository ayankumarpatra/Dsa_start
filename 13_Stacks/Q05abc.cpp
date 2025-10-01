/*
input array given 

day   0   1  2  3  4  5 6
arr  100 80 60 70 60 75 85 

o/p  1    1  1  2  1  4  6 


check till that day its price is high

suppose let day 3 , 70

day 0 100, so leave ,day 1 80 leave

2. 60 , count , 3 . 70 , self , count 

so ans 2 

*/



#include<iostream>
#include<stack>
using namespace std ;

void Stock_Span_Filler(int Stock_price[],int Max_Days[],int Arr_Size){
    int PrevGreatIndex=0,i=0;//using i as current index
    stack <int> st;
    Max_Days[i]=1;
    st.push(i);
    for(i=1;i<Arr_Size;i++){
        //PrevGreatIndex=0;
        while (st.size()>0 && Stock_price[st.top()]<=Stock_price[i])
        {
        st.pop();
        }
        if(st.size()==0){
            Max_Days[i]=i+1;
        }
        else {
            Max_Days[i]=i-st.top();
        }
    st.push(i);
    }
    
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
    int No_of_days;
    cout<<"Enter Approx no of days : ";
    cin>>No_of_days;
    int Stock_Price[No_of_days],Max_Days[No_of_days];

    for(int i=0;i<No_of_days;i++){
        cout<<"Enter Stock price of day "<<i+1<<" : ";
        cin>>Stock_Price[i];
    }

    ArrPrinter(Stock_Price,No_of_days);
    Stock_Span_Filler(Stock_Price,Max_Days,No_of_days);
    ArrPrinter(Max_Days,No_of_days);

    return 0;
}