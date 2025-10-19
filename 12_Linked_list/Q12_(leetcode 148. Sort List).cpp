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
    ListNode* sortList(ListNode* head) {
        if(head==NULL){return NULL;}
        ListNode *ResultNodeHead=head;
        ListNode *ResultNodetail=head;
        head=head->next;
        ResultNodetail->next=NULL;

        while (head!=NULL)
        {
        if(ResultNodeHead->val>=head->val){
            ListNode *temp=head;
            head=head->next;
            temp->next=ResultNodeHead;
            ResultNodeHead=temp;
        }
        else if(ResultNodetail->val<=head->val){
            ListNode* temp=head;
            head=head->next;
            ResultNodetail->next=temp;
            temp->next=NULL;
            ResultNodetail=temp;
        }
        else {
            ListNode* Slow=ResultNodeHead;
            ListNode* fast=ResultNodeHead->next;
            while (fast!=NULL)
            {
                if(head->val>=Slow->val && head->val<=fast->val){
                    break;
                }
            Slow=Slow->next;
            fast=fast->next;
            }
            Slow->next=head;
            head=head->next;
            Slow->next->next=fast;    
        }
        }
        return ResultNodeHead;     
    }
};

int main (){


    return 0;
}
