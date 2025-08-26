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


void display (Node *head){
    Node* temp=head;
    while (temp){
        cout<<temp->val<<" ";
        if (temp==NULL){
            break;
        }
        temp=temp->next;
    }

}

int listsize (Node *head){
    int size=0;
    Node *temp=head;
    while (temp != NULL){
        size++;
        temp=temp->next;
    }
    return size*sizeof(Node);
    
}

/*
my style 

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

but standard is 
whats better , i am checking next , so it will stop at last node only 
*/

void Display_By_Recursion(Node* head) {
    if (head == NULL) {   // base case
        return;
    }
    cout << head->val << " "; // lets say kaam
    Display_By_Recursion(head->next);// lets say call
}

/*
ultra special warning 

if you just replace kaam and call , eg first call then kaam , 
the list will be printed but in reverse order 

    Display_By_Recursion(head->next);
    cout<<head->val<<" "; // it will print in reverse order 
    eg op will be 50 40 30 20 10 

*/
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

/*
prev we do like cout<<(*(*(*a.next).next).next).val<<endl;, to get value of d 

but we can also do like 

*/

cout<<a->next->next->next->val<<"\n";

// see we get 40 in o/p  also we can create a func to display all elements 

display (a);

//how to display size 

cout<<"\n List size is "<<listsize(a);

//How to display the linked list by recursion 
cout<<"\nDisplaying by recursion "<<endl;
Display_By_Recursion(a);
    return 0;
}