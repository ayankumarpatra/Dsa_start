#include<iostream>
using namespace std ;

class Node {
    public :
    int val;
    Node *next;

    Node(int value){
        val=value;
        next=NULL;
    }
};

class Linkedlist {
    public :
    Node *head;
    int size;

    Linkedlist (){
        head=NULL;
        size=0;
    }

    void AddAtHead(int value){
        Node* temp= new Node(value);

        if (size==0){
            head=temp;
            size++;
            return;
        }

        //Node *temphead=head;
        temp->next=head;
        head=temp;
        size++;
    }

    void Display (){
        if (size==0){
            cout<<"Empty list \n";
            return;
        }
        Node*temp =head;
        while (temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void Delete_mid (){
        // added fix for only 1 node 
    if (head!=NULL && head->next!=NULL && head->next->next==NULL){
        cout<<"only 2 elements , deleting the 1 st one \n";
        Node *delnode=head;
        head=head->next;
        size--;
        delete(delnode);
        return;
    }
    Node* slow=head;
    Node* fast=head;
    while (fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*temp2=slow->next->next;
    Node*delnode=slow->next;
    slow->val=slow->next->val;
    slow->next=temp2;
    delete(delnode);
}
};

int main (){

    Linkedlist ll;
    ll.AddAtHead(10);
    ll.AddAtHead(15);
    ll.AddAtHead(25);
    ll.AddAtHead(35);
    ll.Display();

    ll.Delete_mid();
    ll.Display();

    return 0;
}