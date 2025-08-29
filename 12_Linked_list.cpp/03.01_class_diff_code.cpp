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
    Node* tail;
    int size;

    Linkedlist(){ 
        head=tail=NULL;
        size=0;
    }

    void InsertAtHead(int val){
        Node *tempnode= new Node(val);
        if (size==0){
            head=tail=tempnode;
            size++;
        }
        else {
            tempnode->next=head;
            head=tempnode;
        }
    }

    void InsertAtTail(int val){
        Node*temp= new Node (val);
        if (size==0){
            head=tail=temp;
            size++;
        }
        else {
            tail->next=temp;
            tail=temp;
            size++;
        }
    }


    void display (){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main (){

    Linkedlist ll;

    ll.InsertAtHead(20);
    ll.InsertAtHead(10);
    ll.display();

    ll.InsertAtTail(40);
    ll.InsertAtTail(50);
    ll.display();
    return 0;
}