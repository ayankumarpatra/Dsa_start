#include<iostream>
using namespace std ;

class ListNode {
    public :
    int val;
    ListNode *next;

    ListNode (int val){
        this ->val=val;
        this->next=NULL;
    }
};

class Linkedlist {
    public:
    ListNode* head;
    int size;

    Linkedlist(){ 
        head=NULL;
        size=0;
    }
};

void InsertAtHead(ListNode *&head ,int &size,int val){
    ListNode *temp= new ListNode(val);
    temp->next=head;
    head=temp;
    size++;
}


void display (ListNode *head){
    if (head==NULL){
        cout<<"Empty list , nothing to print \n";
        return;
    }
    ListNode *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL){
            return NULL;
        }
        ListNode *temp= head;

        while (temp!=NULL && temp->next!=NULL)
        {   if(temp->val==temp->next->val){
            temp->next=temp->next->next;
            }
            
        else {
         temp=temp->next;
        }
    }
        return temp;  
    }
};


int main (){


    return 0;
}
