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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* curr=head;

        while (curr!=NULL && curr->next!=NULL)
        {
            if (curr->val==curr->next->val){
                ListNode* temp=curr;
                while (temp!=NULL)
                {
                    if (temp->val==curr->val){
                        temp=temp->next;
                    }
                    else{
                        break;
                    }
                }
                curr->next=temp;         
            }
            curr=curr->next;
        }
        return head;
    }
};

int main (){


    return 0;
}
