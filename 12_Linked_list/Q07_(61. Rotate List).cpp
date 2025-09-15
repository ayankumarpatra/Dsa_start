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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL || k==0){
            return head;
        }
        int sizeoflist=0;
        ListNode * templen=head;
        while (templen!=NULL)
        {   sizeoflist++;
            templen=templen->next;
        }
        
        k=k%sizeoflist;

        if(k==0){
            return head;
        }
        ListNode *slow= head;
        ListNode *fast= head;

        while (k-->0)
        {   if(fast->next==NULL){
            fast=head;
        }
            else 
                fast=fast->next;
        }
        
        while (fast->next!=NULL)
        {   
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* temphead = head;
        head=slow->next;
        slow->next=NULL;
        fast->next=temphead;
        
        return head;
    }
};


int main (){


    return 0;
}
