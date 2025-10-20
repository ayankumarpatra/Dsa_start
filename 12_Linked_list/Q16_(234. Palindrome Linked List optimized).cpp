#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode* ReverseList(ListNode* MainList){
        if(MainList==NULL || MainList->next==NULL){
            return MainList;
        }
        ListNode*head=MainList;
        MainList=MainList->next;
        head->next=NULL;

        while (MainList!=NULL)
        {
        ListNode *temp=MainList;
        MainList=MainList->next;
        temp->next=head;
        head=temp;
        }
        return head;
    }


    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=NULL;
        while (fast!=NULL && fast->next!=NULL)
        {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        }
        
        if(fast->next->next!=NULL){prev->next=NULL;}
        slow=ReverseList(slow);

        while (slow!=NULL && head!=NULL)
        {
        if(head->val!=slow->val){
            return false;
        }
        slow=slow->next;
        head=head->next;
        }

        return true;
    }
};


int main (){


    return 0;
}
