#include<iostream>
using namespace std ;

class Node {
    public :
    int val;
    Node* next;

    Node(int value){
        val=value;
        next=NULL;
    }
};

class Linkedlist {
    public :
    Node *head;
    int size;
    Linkedlist(){
        head=NULL;
        size=0;
    }
};

// addathead outside 

void AddAtHead(Node *&head , int &size , int value){// must send by address 
    Node* temp = new Node (value);
    temp->next=head;
    head=temp;
    size++;
}

void DisplayLinkedlist(Node* head){
    if (head==NULL){
        cout<<"Empty Linked list , Nothing to print \n";
        return;
    }
    else{
        Node* temp=head;
        while (temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    cout<<endl;
}

void GetLeftMid(Node *head){// q is just to get left mid value , if said to delete , use & must and write del func inside
    // or if ask to get the node add , will write Node * getleft... and then return slow 
    if (head==NULL){
        cout<<"Empty Node , No left present \n";
        return;
    }
    if(head->next==NULL){
        cout<<"Node contains only 1 element, No left present , so giving that element only"<<head->val<<endl;
        return;

    }
    if (head->next->next==NULL){
        cout<<"Node contains only 2 elements, No exact left present , so giving first element only"<<head->val<<endl;
        return;
    }
    Node *slow=head;
    Node *fast=head;

    while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"value at left mid node is : "<<slow->val<<endl;
}

int main (){
    Linkedlist ll;
    DisplayLinkedlist(ll.head);
    AddAtHead(ll.head,ll.size,30);
    AddAtHead(ll.head,ll.size,20);
    AddAtHead(ll.head,ll.size,10);
    DisplayLinkedlist(ll.head);

    GetLeftMid(ll.head);
    DisplayLinkedlist(ll.head);

    return 0;
}