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
        if(head==NULL || head->next==NULL){
            return head;
        }

        
        ListNode*curr=head;
        ListNode*Prev_tail=NULL;
        int grouplen=1;
        
        while (curr!=NULL)
        {
            ListNode* Group_start=curr;
            int currlen=0;

            ListNode * temp=curr;
            while(currlen<grouplen && temp!=NULL ){
                currlen++;
                temp=temp->next;
            }

            ListNode* Next_group=temp;

            if(currlen%2==0){
               ListNode* prev=Next_group;
               ListNode* Curr_node=Group_start;

                for(int i=0;i<grouplen;i++){
                    ListNode* Next_temp =Curr_node->next;
                    Curr_node->next=prev;

                    prev=Curr_node;
                    Curr_node=Next_temp;
                }
                
                if(Prev_tail!=NULL){
                    Prev_tail->next=prev;
                }
                else{
                    head=prev;
                }

                Prev_tail=Group_start;
                
            }
            else {
                Prev_tail=Group_start;
                for(int i=1;i<currlen;i++){
                    Prev_tail=Prev_tail->next;
                }
            }
            curr=Next_group;
            grouplen++; 
    }
    return head;
}
};


int main (){


    return 0;
}
