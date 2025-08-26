#include<iostream>
using namespace std;

class Node {
    public : 
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void Display_By_Recursion(Node*head){
    if(head->next==NULL){
        cout<<head->val<<" ";
        return;
    }
    else {
        cout<<head->val<<" ";
        return Display_By_Recursion(head->next);
    }
}
int main (){
Node * a=new Node(10);
Node * b=new Node(20);
Node * c=new Node(30);
Node * d=new Node(40);
Node * e=new Node(50);

a->next=b;
b->next=c;
c->next=d;
d->next=e;


//How to display the linked list by recursion 
cout<<"\nDisplaying by recursion "<<endl;
Display_By_Recursion(a);
    return 0;
}