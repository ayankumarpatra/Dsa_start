//86. Partition List

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
    ListNode* partition(ListNode* head, int x) {
    ListNode *CurrNode=head;

    ListNode* left=new ListNode(-1);
    ListNode* right=new ListNode(-1);
    ListNode*Finalnode=left;
    ListNode*connectnode=right;

    while (CurrNode!=NULL)
    {
    if(CurrNode->val<x){
        left->next=CurrNode;
        left=CurrNode;
    }
    else if(CurrNode->val>=x){
        right->next=CurrNode;
        right=CurrNode;
    }
    CurrNode=CurrNode->next;
    }
    right->next=NULL;
    left->next=connectnode->next;

    return Finalnode->next;
    }
};


int main (){


    return 0;
}
