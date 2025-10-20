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
        if(head==NULL || left==right){
            return head;
        }

        int i;
        ListNode*LeftLastNode=head;
        for(i=1;i && LeftLastNode->next!=NULL ;i++){
            LeftLastNode=LeftLastNode->next;
            if(i+1==left){
                break;
            }
        }
        ListNode*Midnode=LeftLastNode->next;
        ListNode*Midnodeconnector
        while (Midnode!=NULL)
        {
            /* code */
        }
        
    }
};


int main (){


    return 0;
}
