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
    ListNode* deleteMiddle(ListNode* head) {

        // edge case only 1 node

        if (head==NULL || head->next==NULL){
            return NULL;
        }

        // 2 node only

        if (head->next->next==NULL){
            head->next=NULL;
            return head;
        }

        ListNode* slow=head;
        ListNode* backtrack=NULL;
        ListNode* fast=head->next;
        int len=0;

        while (fast!=NULL)
        {
            if (fast!=NULL && fast->next!=NULL){
                fast=fast->next;
                len++;
                if (fast!=NULL && fast->next!=NULL){
                    fast=fast->next;
                    len++;
                }
                else {
                    break;
                }
            }

            else {
                break;
            }

            backtrack=slow;
            slow=slow->next;
        }
        
        if (len%2 !=0 ){
            backtrack->next=slow->next;
        }
        else{
            slow->next=slow->next->next;
        }

        return head;
    }
};


int main (){


    return 0;
}
