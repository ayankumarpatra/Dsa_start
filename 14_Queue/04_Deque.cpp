#include<iostream>
#include<stack>
#include<vector>
using namespace std ;

/*

deque is a doubly ended queue , means here like normal queue 

push back , pop front possible and also 

push front pop back possible and both at o(1) time complexity 


usually implemented by array or doubly linked list 
*/
class node {
    public:
    int val;
    node* prev;
    node* next;
    
    node(int value){
        val=value;
        prev=next=NULL;
    }
};

class Deque{
    public:
    node* head;
    node* tail;
    int size;
    // usually queue push back , pop front 
    /*
        queue structure 

        front     back
        head       tail
    */
    Deque(){
        head=tail=NULL;
        size=0;
    }

    void push (int num){// push back
        node* temp=new node(num);
        if(size==0){
            head=tail=temp;
        }
        else {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }

        size++;
    }

    void pop(){// pop front , head
        if(size==0){
            cout<<"Empty Queue , cant pop \n";
            return;
        }
        else if(size==1){
            delete(head);
            head=tail=NULL;
        }
        else{
            node*temp= head->next;
            delete(head);
            temp->prev=NULL;
            head=temp;
            size--;
        }
    }

// now extra functions for deque 
    void push_front(int num){
        node* temp=new node(num);
        if(size==0){
            head=tail=temp;
        }
        else {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }

        size++;
    }

    void pop_back(){// to do this only i have to use double linked list , for single it will take o(n) time 
        if(size==0){
            cout<<"Empty Queue , cant pop \n";
            return;
        }
        else if(size==1){
            delete(head);
            head=tail=NULL;
        }
        else{
            node*temp= tail->prev;
            delete(tail);
            temp->next=NULL;
            tail=temp;
            size--;
        }
    }

 
};

/*
or you can use built in stl deque 

#include<deque>

rest just check the functions eg push_back

*/

int main (){

    
    return 0;
}