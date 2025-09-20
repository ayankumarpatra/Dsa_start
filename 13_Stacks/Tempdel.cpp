
#include<iostream>
#define MAX 100

using namespace std ;


template <typename T> struct Stack {
    private:
        int sizex = 0;
    public:   
    int top  = -1;
    T data[MAX]; 
    
    bool isFull(){
        return (top +1 == MAX);
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(int val){
        if(isFull()){
            throw exception("Fuck you bitch!!");
            return;
        }
        data[++top] = val;
    }

    int pop(){
        if(isEmpty()){
             throw exception("Virgin bitch!!");
            return;
        }
        return data[top--]; 

    }
   
    int size(){
        return top + 1;
    }
};


void AddAtBottom(Stack<int> *st ,int val){
    if(st->size() == 0) {
        st->push(val);
        return;
    }
    int x=st->top;
    st->pop();
    AddAtBottom(st,val);
    st->push(x);
}

void LIFOStackDisplay(Stack<int> *st){
    if(st->size()==0) return;
    int x=st->top;
    cout<<x<<" ";
    st->pop();
    LIFOStackDisplay(st);
    st->push(x);
}


int main (){

Stack<int> st;

int total,element,i=1;
    cout<<"Enter how many elements you wish to keep into the stack : ";
    cin>>total;
    if(total<=0){
        cout<<"Invalid input ";
    }
    else {
            Stack<int>temp1;

        while (total-->0)
        {
        cout<<"Enter element "<<i++<<" : ";
        cin>>element;
        st.push(element);
        }
    }
    return 0;
}