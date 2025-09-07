#include<iostream>
using namespace std ;

class Node {
    public :
    int val;
    Node *next;

    Node (int val){
        this ->val=val;
        this->next=NULL;
    }
};

class Linkedlist {
    public:
    Node* head;
    int size;

    Linkedlist(){ 
        head=NULL;
        size=0;
    }
};

void InsertAtHead(Node *&head ,int &size,int val){
    Node *temp= new Node(val);
    temp->next=head;
    head=temp;
    size++;
}


void display (Node *head){
    if (head==NULL){
        cout<<"Empty list , nothing to print \n";
        return;
    }
    Node *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


void DeletenthNodefromEnd(Node*& head,int &sizemain,int pos){
    int size=0;
    Node*temp=head;
    while(temp){
        size++;
        temp=temp->next;
    }
    if (pos>size || pos<=0 ){
        cout<<"Invalid position to delete\n";
        return;
    }
    if (pos==size ){
        Node*tempdel=head;
        head=head->next;
        delete(tempdel);
        sizemain--;
        return;
    }
    Node*temp1=head;
    for(int i=1;i<size-pos;i++){
        temp1=temp1->next;
    }
    Node*temp2=temp1->next;
    temp1->next=temp1->next->next;
    delete(temp2);
    sizemain--;
}

int main (){

    Linkedlist ll;
    InsertAtHead(ll.head,ll.size,30);
    InsertAtHead(ll.head,ll.size,20);
    InsertAtHead(ll.head,ll.size,10);
    display(ll.head); 

    DeletenthNodefromEnd(ll.head,ll.size,1);
    display(ll.head); 
    DeletenthNodefromEnd(ll.head,ll.size,2);
    display(ll.head); 
    return 0;
}