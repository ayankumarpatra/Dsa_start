// linkedlist 1. add at head , tail , any pos 

#include<iostream>
using namespace std ;

class Node {
    public : 
    int val;
    Node* next;

    Node (int val){
        this->val=val;
        this->next=NULL;
    }
};

class Linkedlist {
    public :
    Node *head;
    Node *tail;
    int size;

    Linkedlist (){
        head=tail=NULL;
        size=0;
    }

    // 1. insert at tail 
    void Insertaattail(int num){
        Node *temp=new Node (num);
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

    void InsertatHead(int n){
        Node*temp=new Node(n);
        temp->next=head;
        head=temp;
        size++;
    }

    void InsertatPos(int pos , int val){
        if (pos <= 0 || pos > size + 1) {
            cout << "Invalid position\n";
            return;
        }

        if(size==0 || pos==1){
            InsertatHead(val);
            return;
        }
        if (pos==size+1){
            Insertaattail(val);
            return;
        }

        Node *temp= new Node(val);

        Node*prev=head;
        for (int i=1;i<pos-1;i++){
            prev=prev->next;
        }
        Node*tempnext=prev->next;

        prev->next=temp;
        temp->next=tempnext;

        size++;
    }

    void display (){
        if (size==0){
            cout<<"Empty linkedlist , nothing to print ";
            return ;
        }
        Node*temp=head;
        while (temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }



    void Deleteatpos(int pos){
        if (pos<=0 || pos>size){
            cout<<"Invalid position \n";
            return ;
        }
        if (size==0){
            cout<<"Empty list cant delete \n";
            return;
        }
        if (size==1){
            delete head;
            head=tail=NULL;
            size--;
            return;
        }
        if (pos==1){
            Node *delnode=head;
            head=head->next;
            delete delnode;
            if (head==NULL) {
                tail=NULL;
            }
            size--;
            return;
        }
        Node*prev=head;
        for (int i=1;i<pos-1;i++){
            prev=prev->next;
        }
        Node* delnode=prev->next;
        prev->next=delnode->next;

        if (delnode==tail){
            tail=prev;
        }
        delete delnode;
        size--;
    }


    void GetelementAt(int pos){
        if(pos>size+1 || pos<=0){
            cout<<"invalid position \n";
            return ;
        }
        if (pos==1){
            cout<<"value at head is : "<<head->val<<endl;
            return;
        }
        if(pos==size){
            cout<<"Value at tail is : "<<tail->val<<endl;
            return;
        }
        Node*temp=head;
        for (int i=1;i<pos;i++){
            temp=temp->next;
        }
        cout<<"Value at pos "<<pos<<" is : "<<temp->val<<endl;;
    }

    ~Linkedlist(){
        Node*temp=head;
        while(temp!=NULL){
            Node*next=temp->next;
            delete temp;
            temp=next;
        }
    }
};

int main (){

    Linkedlist ll;
    ll.Insertaattail(50);
    ll.Insertaattail(60);
    ll.Insertaattail(70);

    ll.display();

    ll.InsertatHead(30);
    ll.InsertatHead(20);
    ll.InsertatHead(10);

    ll.display();

    ll.InsertatPos(3,3);
    ll.InsertatPos(2,2);
    ll.InsertatPos(1,1);

    ll.display();

    ll.Deleteatpos(1);
    ll.Deleteatpos(2);
    ll.Deleteatpos(7);
    ll.display();


    ll.GetelementAt(2);
    ll.GetelementAt(1);
    ll.GetelementAt(4);
    ll.GetelementAt(40);
    return 0;
}