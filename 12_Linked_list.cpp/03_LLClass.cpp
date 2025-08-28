#include<iostream>
using namespace std ;

class Node {
    public :
    int val ;
    Node *next ;

    Node (int  val){
        this->val=val;
        this->next=NULL;
    }

};

class Linkedlist {
    public :
    Node *head;
    Node* tail;
    int size ;

    Linkedlist(){
        head=tail=NULL;
        size=0;
    }

    void AddAtHead(int n){
        Node *temp= new Node (n);
        if (size ==0){
            head=tail=temp;
            size++;
        }
       else{
        Node*temp1 = head;
        head=temp;
        head->next=temp1;
        size++;
       }
        
    }

    void AddAtTail(int x){
        Node*temp= new Node(x);
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

    void InsertAtPos(int pos,int val){
        if (pos<1 || pos>size+1){
            cout<<"invalid position to insert ";
            return;
        }
        if (pos==size+1){
            AddAtTail(val);
            return;
        }
        if (pos==1){
            AddAtHead(val);
            return;
        }
        else {
            Node*temp = new Node(val);
            Node*prev=head;
            Node*tempafter;
            for (int i=1;i<pos-1;i++){
                prev=prev->next;

            }
            temp->next=prev->next;
            prev->next=temp;
            size++;

        }
    }

    void display (){
        Node* temp=head;
        while (temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    

};


int main (){

    Linkedlist ll;
    ll.AddAtHead(50);
    ll.display();
    ll.AddAtHead(60);
    ll.AddAtHead(70);
    ll.display();

    ll.AddAtTail(100);
    ll.AddAtTail(99);
    ll.display();

    ll.InsertAtPos(2,1234);
    ll.display();
    return 0;
}