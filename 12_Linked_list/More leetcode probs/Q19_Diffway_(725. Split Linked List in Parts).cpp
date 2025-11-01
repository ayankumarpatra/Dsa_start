/*

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int length=0;
        ListNode*curr=head;
        while (curr!=NULL)
        {
        curr=curr->next;
        length++;
        }

        int MaxPossibleInEachPart,Remaining,currpart;
            MaxPossibleInEachPart=length/k;
            Remaining=length%k;

        vector <ListNode*> Splitheads;
        curr=head;

        ListNode* pushhead;
        ListNode* prev;


        for(int i=0;i<k;i++){
            if(curr==NULL){
                Splitheads.push_back(curr);
            }

            else {
                currpart=MaxPossibleInEachPart+(Remaining>0? 1:0);

                if(Remaining>0) Remaining--;

                pushhead=curr;
                for(int j=0;j<currpart;j++)
                {
                prev=curr;
                curr=curr->next;
                }

                if(prev!=NULL){
                    prev->next=NULL;
                }
                
                Splitheads.push_back(pushhead);
            }
        }
        return Splitheads;     
    }
};

int main (){


    return 0;
}

*/



