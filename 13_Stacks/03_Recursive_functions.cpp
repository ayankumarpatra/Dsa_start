#include<iostream>
#include<stack>
using namespace std ;

void DisplayStackbyRec(stack<int>&st){
    if(st.size()==0) return ;
    int x= st.top();
    cout<<x<<" ";
    st.pop();
    DisplayStackbyRec(st);
    st.push(x);
}

int main (){

stack<int> st;

int total,element,i=1;
    cout<<"Enter how many elements you wish to keep into the stack : ";
    cin>>total;
    if(total<=0){
        cout<<"Invalid input ";
    }
    else {
        while (total-->0)
        {
        cout<<"Enter element "<<i++<<" : ";
        cin>>element;
        st.push(element);
        }

    }

    DisplayStackbyRec(st);
    return 0;
}