#include<iostream>
using namespace std;

/*
benefits 

1. display linked list in reverse order 


remember old pattern display by recursion 

display (head){
if(head==null){
return;
}

cout<<head->val; // print in normal order 
display(head->next);

// but if done
disply(head->next);// print in reverse order 
cout<<head->val;

}


2. if any node given , we can reach entire list 
    single link list given , only forward possible 





creating functions to 
1. insert (head , tail , index )
2. delete (head , tail , index )
3. get value (head , tail , index )
*/


class Node{// for doubly linked list
    public:
    Node* prev;
    Node* head;
    int val;
    Node* next;
    Node * tail;

    Node(int value){
        prev=NULL;
        val=value;
        next=NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* prev;
    Node* head;
    int val;
    Node* next;
    Node* tail;
    int size;

    DoublyLinkedList(int value){
        prev=NULL;
        val=value;
        next=NULL;
        size=0;
    }

    void AddAthead(int val ){
        if(size==0){
            Node * temp= new Node(val);
            head
        }
    }
};


int main(){



return 0;
}