

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

int main (){

Node a(10),b(20),c(30),d(40);
a.next=&b;
b.next=&c;
c.next=&d;

cout<<((a.next)->next)->val<<endl;

// if need d value by a , we can do 

cout<<(*(*(*a.next).next).next).val<<endl;// last time no need to use next , as we need val, use val only 

/*
      (*(*(*a.next).next).next).val;
    =(*(*(b).next).next).val;
    =(*(*c).next).val
    =(*d).val
    =d.val;


    we can print all the value by using a loop

*/
Node* temp =&a;
int breaker=1;
while (temp->next!=0 ){
    cout<<temp->val<<" , "<<endl;
    if(temp->next==NULL){
        breaker=0;
    }
    if (!breaker){
        break;
    }
    temp=temp->next;
}


    return 0;
}