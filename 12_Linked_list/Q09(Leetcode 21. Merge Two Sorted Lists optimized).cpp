#include<iostream>
using namespace std ;

class ListNode{
    public:
    int val;
    ListNode*next;

    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){return list2;}
        else if(!list2){return list1;}
        ListNode *Result;

        
        if(list1->val<=list2->val){
         Result=list1;
         list1=list1->next;
        }
        else {
         Result=list2;
         list2=list2->next;
        }
        ListNode *ResultHead=Result;

        while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
         Result->next=list1;
         Result=Result->next;
         list1=list1->next;
        }
        else {
         Result->next=list2;
         Result=Result->next;
         list2=list2->next;
        }
        }
        if(list1!=NULL){Result->next=list1;}
        else if(list2!=NULL){Result->next=list2;}

        return ResultHead;
    }
};




int main (){

    return 0;
}