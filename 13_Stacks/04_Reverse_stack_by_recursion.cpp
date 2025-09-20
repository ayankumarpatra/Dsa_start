#include<iostream>
#include<stack>
using namespace std ;

void PushAtBottom(stack<int> *st,int val){
    if(st->size()==0) {
        st->push(val);
        return;
    }

    int x=st->top();
    st->pop();
    PushAtBottom(st,val);
    st->push(x);

}

void ReverseOriginalStack(stack<int> *st){
    if(st->size()==0) return;

    int x=st->top();
    st->pop();
    ReverseOriginalStack(st);
    PushAtBottom(st,x);
    
}

void DisplayLIFOStack(stack<int>* st){
    if(st->size()==0){
        return;
    }
    int x=st->top();
    cout<<x<<" ";
    st->pop();
    DisplayLIFOStack(st);
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

    DisplayLIFOStack(&st);
    ReverseOriginalStack(&st);
    DisplayLIFOStack(&st);
    return 0;
}



