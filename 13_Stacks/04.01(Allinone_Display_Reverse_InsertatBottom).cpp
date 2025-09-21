#include<iostream>
#include<stack>

using namespace std;

void DisplayLIFOstack(stack<int>* st){
    if(st->size()==0) {
        cout<<endl;
        return;}
    int x=st->top();
    cout<<x<<" ";
    st->pop();
    DisplayLIFOstack(st);
    st->push(x);
}

void InsertAtBottom(stack<int> * st,int value){
    if(st->size()==0){
        st->push(value);
        return;
    }
    int x=st->top();
    st->pop();
    InsertAtBottom(st,value);
    st->push(x);
}

void ReverseMainStack(stack<int>* st){
    if(st->size()==0){
        return;
    }
    int x=st->top();
    st->pop();
    ReverseMainStack(st);
    InsertAtBottom(st,x);
}

int main (){
int ems,element,i=1;
    stack<int> st;
    cout<<"Enter the no of elements to store in stack : ";
    cin>>ems;

    while (ems-->0){
        cout<<"Enter the value "<<i++<<" : ";
        cin>>element;
        st.push(element);
    }

    DisplayLIFOstack(&st);
    InsertAtBottom(&st,56);
    
    DisplayLIFOstack(&st);

    ReverseMainStack(&st);
    DisplayLIFOstack(&st);

// if the stack size is full and still you try to push elements , then it will overflow 

// or in a empty stack we try to top or pop it will underflow as no element wass there 
    return 0;
}