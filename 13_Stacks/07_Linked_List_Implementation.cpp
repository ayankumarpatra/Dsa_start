#include<iostream>
using namespace std ;

// Actually its not the class implementation , actually its the classs node implementation . 

// means nothing 
/*
1. create a linked list node 
2. lets Stack is [ 10 20 30...

first time push 10 , so head 10 ,
next push 20 here temp->next=10 , then move head to 20 

then push 30 ,
    now again temp ->next = head;
    head=temp


// Now top element 
st.top = head->val;


//pop
haed=head->next;

*/

class Node {
    public:
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        next=NULL;
    }
};

class Stack {
    public:
    Node* head;
    int size;
    Stack(){
        head=NULL;
        size=0;
    }

    void push(int x){
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        size++;
    }

    void pop(){
        if(size==0){
            cout<<"Empty Stack , cant pop\n";
            return;
        }
        Node * temp=head;
        head=head->next;
        delete(temp);
        size--;
    }

    int top(){
        if(size==0){
            cout<<"cant get top element from an empty Stack\n";
            return -1;
        }
        return head->val;
    }


    void display(){
        if(head==NULL){
            cout<<"Empty list , nothing to display \n";
        }
        Node* temp = head;
        while (temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
     
};

int main (){

    return 0;
}