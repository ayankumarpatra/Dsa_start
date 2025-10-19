// 23.Merge k Sorted Lists

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
    ListNode* Merge2List(ListNode* list1, ListNode* list2){
        if(list1==NULL){return list2;}
        else if(list2==NULL){return list1;}
        ListNode*Resultnode=new ListNode(-1);
        ListNode*head=Resultnode;
        ListNode*temp;
        while (list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp=list1;
                list1=list1->next;
                Resultnode->next=temp;
                Resultnode=temp;
            }
            else {
                temp=list2;
                list2=list2->next;
                Resultnode->next=temp;
                Resultnode=temp;
            }
            
        }
        if(list1!=NULL){Resultnode->next=list1;}
        else if(list2!=NULL){Resultnode->next=list2;}
        else Resultnode->next=NULL;

        return head->next;
    }
/*
    ListNode* Sort1list (ListNode* List){
        if(List==NULL || List->next==NULL){return List;}
        ListNode* head =List;
        ListNode* tail=List;
        List=List->next;
        tail->next=NULL;

        while (List!=NULL)
        {
        // INSERTING before
            if(List->val<=head->val){
                ListNode*temp=List;
                List=List->next;

                temp->next=head;
                head=temp;
            }

            // INSERTING after
            else if(List->val>=tail->val){
                ListNode*temp=List;
                List=List->next;

                tail->next=temp;
                temp->next=NULL;
                tail=temp;
            }


        // INSERTING mid
        else {
            ListNode*slow=List;
            ListNode*fast=List->next;
            while (fast!=NULL)
            {
                if(List->val>=slow->val && List->val<=fast->val){
                    break;
                }
                slow=slow->next;
                fast=fast->next;
            }
            ListNode*temp=List;
            List=List->next;
            slow->next=temp;
            temp->next=fast;

        }
        }
        return head;
    }
    */

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while (fast!=NULL && fast->next!=NULL)
        {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        }
        // now mid is slow 
        prev->next=NULL;
        
        ListNode*left=sortList(head);
        ListNode*right=sortList(slow);

        return Merge2List(left,right);
    }
};

int main (){


    return 0;
}
