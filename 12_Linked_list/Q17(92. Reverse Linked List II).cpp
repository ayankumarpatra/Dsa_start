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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right || head->next==NULL){
            return head;
        }
        ListNode* temp=new ListNode(-1);
        temp->next=head;

        ListNode* prev=temp;

        int i=1;
        for(i;i<left;i++){
            prev=prev->next;
        }

        ListNode* curr =prev->next;
        ListNode* next=NULL;

        for(i=left;i<right;i++){
            next=curr->next;
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
        }

        return temp->next;
    }

};


int main (){


    return 0;
}
