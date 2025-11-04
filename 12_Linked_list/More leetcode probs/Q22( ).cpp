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
        
        ListNode* Current_Node=head;

        ListNode* PrevNode=NULL;
        int Mainindex=1;

        while (Current_Node!=NULL)
        {
            int Currlen=0;
            ListNode*LastNode=Current_Node;

            for(int i=0;i<Mainindex && LastNode!=NULL;i++){
                Currlen++;
                LastNode=LastNode->next;
            }
            
            if(Currlen%2==0){
                ListNode*Grouphead=Current_Node;
                ListNode*prev=NULL;
                ListNode*curr=Current_Node;

               for(int i=0;i<Currlen;i++)
                {
                    ListNode* NextNode=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=NextNode;               
                }

                if(PrevNode!=NULL){
                    PrevNode->next=prev;
                }
                else {
                    head=prev;
                }

                Grouphead->next=curr;

                PrevNode=Grouphead;
                Current_Node=curr;
            }

            else {
                while (Currlen-->0)
                {
                    PrevNode=Current_Node;
                    Current_Node=Current_Node->next;
                }
                
            }

            Mainindex++;
        }
        
        return head;
    }
};


int main (){



    return 0;
}

