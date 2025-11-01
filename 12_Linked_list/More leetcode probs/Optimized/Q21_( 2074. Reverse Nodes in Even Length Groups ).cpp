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

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int Range=1,curlen;

        ListNode*curr =head;
        ListNode*Temphead;
        ListNode*prev;
        ListNode*next;
        ListNode*temp;
        ListNode*Firstnode;

        while (curr!=NULL)
        {
            curlen=0;
            for(int i=0;i<Range;i++){
                curlen++;
            }
            Firstnode=curr;
            curr=curr->next;
            prev=curr;
            curr=curr->next;

            if (curlen%2==0){
                while (curlen-->0)
                {
                    next=curr->next;
                    curr->next=prev;

                    cur
                }
                
            }
            prev=curr;
            curr=curr->next;
        }
        
    }
};


int main (){


    return 0;
}
