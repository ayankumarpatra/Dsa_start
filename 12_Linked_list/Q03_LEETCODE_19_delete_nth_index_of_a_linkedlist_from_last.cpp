/*

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode*tempcount=head;
        while(tempcount!=NULL){
            size++;
            tempcount=tempcount->next;
        }
        if (n>size || n<=0){
            cout<<"Invalid position\n";
            return NULL;
        }
        if(n==size){
            ListNode*tempnode=head;
            head=head->next;
            delete(tempnode);
            return head;
        }
        ListNode* temp2=head;
        for (int i=1;i<size-n;i++){
            temp2=temp2->next;
        }
        ListNode*delnode=temp2->next;
        temp2->next=temp2->next->next;
        delete(delnode);
        return head;
    }
};

int main (){


    return 0;
}


better , 2 pointer algo 
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL){// if head null meanss list is empty 
            return NULL;
        }
        ListNode *fast=head;//declare both fast and slow pointer
        ListNode *slow=head;

        for (int i=0;i<n;i++){// move the fast pointer upto n times
            if(fast==NULL){// if fast become null in btn , means size given is more than the actual size ,
                // i mean it will be null at the last node only 
                cout<<"Invalid position\n";
                return head;
            }
            fast=fast->next;// update fast to fast -> next 
        }
    if (fast==NULL){// if the fast is null at n , so it will be the last pos from last, mean first position or the head
        ListNode*temphead=head;
        head=head->next;
        delete(temphead);
        return head;
    }

    while (fast->next!=NULL){// to get the pos to delete move both fast and slow till fast become null;
        fast=fast->next;
        slow=slow->next;
    }
    // noow delete the slow pointer 
    ListNode*delnode=slow->next;
    slow->next=slow->next->next;
    delete(delnode);
    return head;
    }
};

int main (){


    return 0;
}
