#include<iostream>
using namespace std ;

class Node {
    public :
    int val;
    Node *next;

    Node (int val){
        this->val=val;
        this->next=NULL;
    }

};

class Linkedlist {
    public :
    Node * head;
    int size;

    Linkedlist(){
        head=NULL;
        size=0;
    }


void DelByValue (int value){
    if (size==0){
        cout<<"cant delete from an empty node";
    }
    Node*temp=head;

    if(temp->val==value && size==1){
        head=NULL;
        delete(temp);
        size--;
        return;
    }
        
    if(temp->val==value){
        head=temp->next;
        delete(temp);
        size--;
        return;
    }

    int found=0;
    while(temp){
        if(temp->next->val==value){
            found=1;
            break;
        }
        temp=temp->next;
    }
    if (found){
    Node*temp2 =temp->next->next;
    temp->next=temp2;  
    size--;
    }
    else {
        cout<<"Not found";
    }
    // code runs if the value present , else it throws error , will check later 

}

void DelHead(){
    Node*temp=head;
    if(size==0){
        cout<<"Cant delete empty node\n";
        return;
    }
    if(size==1){
        head=NULL;
        delete(temp);
        size--;
        return;
    }
    head=head->next;
    delete(temp);
    size--;
}

void DelEnd(){
    Node*temp=head;
    if(size==0){
        cout<<"Cant delete empty node\n";
        return;
    }
    if(size==1){
        head=NULL;
        delete(temp);
        size--;
        return;
    }
    while(temp->next->next){
        temp=temp->next;
    }
    Node*delnode=temp->next;
    delete(delnode);
    temp->next=NULL;
    size--;

}


void DelByIndex(int index){
    if (size==0){
        cout<<"cant delete from an empty node";
        return;
    }
    if (index>size+1){
        cout<<"Invalid position to delete";
        return;
    }
    if (index==1){
        DelHead();
        return;
    }
    if(index==size){
        DelEnd();
        return;
    }
    Node*temp=head;
    int pos=1;
    while(temp){
        if(pos==index){
            break;
        }
        temp=temp->next;
        pos++;
    }
    temp->next = temp -> next -> next;
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



    void InsertatHead(int n){
        Node*temp=new Node(n);
        temp->next=head;
        head=temp;
        size++;
    }



};
int main (){

    Linkedlist ll;
    
    ll.InsertatHead(10);
    ll.InsertatHead(10);
    ll.InsertatHead(20);
    ll.InsertatHead(30);
    ll.InsertatHead(40);
 
    ll.display();
    
    ll.DelByIndex(1);
    ll.display();

    ll.DelByValue(40);
    ll.display();

    ll.DelByIndex(1);
    ll.display();


    return 0;
}
