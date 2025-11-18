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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        while (head!=NULL && head->val==val ){
            head=head->next;
        }
        ListNode*temp=head;
        while (temp!=NULL)
        {
            ListNode*lastn=temp->next;
            while (lastn!=NULL && lastn->val==val)
            {
                lastn=lastn->next;
            }
            temp->next=lastn;
            temp=temp->next;
        }
        
        return head;
    }
};

int main (){


    return 0;
}
