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

        ListNode* ResultNode = new ListNode(-1);
        ListNode* tail=ResultNode;

        while (list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val){
                tail->next=new ListNode(list1->val);
                tail=tail->next;
                list1=list1->next;
            }
            else if(list2->val<list1->val){
                tail->next=new ListNode(list2->val);
                tail=tail->next;
                list2=list2->next;
            }
        }

        if(list1!=NULL){tail->next=list1;}
        else if(list2!=NULL){tail->next=list2;}
        
        return ResultNode->next;

    }
};




int main (){

    return 0;
}