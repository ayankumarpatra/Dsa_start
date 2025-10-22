#include<iostream>
#include<vector>
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

class Solution {
public:
    ListNode* merge2list(ListNode*mainlist,ListNode* Reverselist){
        if(mainlist==NULL){
            return Reverselist;
        }
        else if(Reverselist==NULL){
            return mainlist;
        }
        ListNode*head=new ListNode(-1);
        ListNode*currhead=head;
        ListNode*temp;
        int i=1;
        while (mainlist!=NULL && Reverselist!=NULL)
        {
        if(i%2!=0){
            currhead->next=mainlist;
            mainlist=mainlist->next;
            currhead=currhead->next;
        }
        else if(i%2==0){
            currhead->next=Reverselist;
            Reverselist=Reverselist->next;
            currhead=currhead->next;
        }
        i++;
        }
        if(mainlist!=NULL){
            currhead->next=mainlist;
        }
        else if(Reverselist!=NULL){
            currhead->next=Reverselist;
        }
        return head->next;
    }

   void reorderList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode*Mainhead = head;

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode*prev=NULL;

        while (fast!=NULL && fast->next!=NULL )
        {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        }
        // now slow is at mid, prev is at last allowed node for the first half of the list ;

        prev->next=NULL;
        
        ListNode * Reversehead=slow;
        slow=slow->next;
        Reversehead->next=NULL;
        ListNode * temp;

        while (slow!=NULL)
        {
        temp=slow;
        slow=slow->next;
        temp->next=Reversehead;
        Reversehead=temp;
        }
        

    Mainhead= merge2list(Mainhead,Reversehead);
        
    }     
};


int main (){


    return 0;
}
