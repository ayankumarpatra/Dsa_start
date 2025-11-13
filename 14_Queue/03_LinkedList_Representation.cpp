#include<iostream>
#include<stack>
#include<vector>

/*
push back 
pop front 

front ..... back 


options 

1.Push insertat tail
2. pop deleteathead
3. front = head val , top = tail val 
4. size as linkedlist size 
*/

class node {
    public:
    int val;
    node*next;

    node(int val){
        this->val=val;
        next=NULL;
    }

};


class LinkedList{
    public:
    node* head;
    node* tail;
    int size;

    LinkedList(){
        head=tail=NULL;
        size=0;
    }

    void push (int num){//insertatTail, push back
        node* temp=new node(num);
        if (size==0){
            head=tail=temp;
        }
        else {
            tail->next=temp;
            tail=temp;
        }
    }

    void pop(){// pop front , delete front
        if (size==0){
            cout<<"Empty Queue , cant pop\n";
            return;
        }
        else {
            node* temp=head->next;
            delete(head);
            head=temp;
        }
    }

    int top(){
        if (size==0){
            cout<<"Empty Queue no top element \n";
            return;
        }
        else {
            return tail->val;
        }
    }

};

using namespace std ;
int main (){

    
    return 0;
}