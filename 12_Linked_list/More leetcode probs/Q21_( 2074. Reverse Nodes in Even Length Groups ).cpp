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

        int Mainindex=2;

        ListNode * Prevnode=head;
        ListNode * Curr_Node=head->next;
        
        while (Curr_Node!=NULL)
        {
            int Currlen=0;
            ListNode* LastNode=Curr_Node;

            for(int i=0;i<Mainindex && LastNode!=NULL ;i++){
                Currlen++;
                LastNode=LastNode->next;
            }

            
            if(Currlen%2==0){
                ListNode* StartNode=Curr_Node;
                ListNode * NextConnectNode=LastNode;

                for(int i=0;i<Currlen;i++){
                    ListNode* NextNode=Curr_Node->next;
                    Curr_Node->next=NextConnectNode;

                    NextConnectNode=Curr_Node;
                    Curr_Node=NextNode;
                }
                if(Prevnode==NULL){
                    head=NextConnectNode;
                }
                else {
                Prevnode->next=NextConnectNode;
                }

                Prevnode =StartNode;
            }

            else {
                for(int i=0;i<Currlen;i++){
                    Prevnode=Curr_Node;
                    Curr_Node=Curr_Node->next;
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
