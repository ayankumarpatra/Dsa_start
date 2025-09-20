#include<iostream>
#include<stack>
using namespace std ;

void AddatBottom(stack<int> *st, int val){
    if(st->size()==0){
        st->push(val);
        return;
    }
    int x=st->top();
    st->pop();
    AddatBottom(st,val);
    st->push(x);

}

void DisplayNormalStack(stack<int> *st){
    if(st->size()==0){
        return ;
    }
    int x=st->top();
    cout<<x<<" ";
    st->pop();
    DisplayNormalStack(st);
    st->push(x);
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
        stack<int>temp1;

        while (total-->0)
        {
        cout<<"Enter element "<<i++<<" : ";
        cin>>element;
        st.push(element);
        }
    }

    DisplayNormalStack(&st);
    cout<<endl;
    AddatBottom(&st ,48);
    DisplayNormalStack(&st);
    cout<<endl;

    return 0;
}