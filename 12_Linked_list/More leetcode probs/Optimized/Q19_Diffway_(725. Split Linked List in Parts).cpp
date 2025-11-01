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

//Divide in k part 
class Solution {
public:

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*prev=head;
        int length=0;
        while (prev!=NULL)
        {
            length++;
            prev=prev->next;
        }

        int UsualSize=length/k,Remaining=length%k,Currlen;
        ListNode*Pushhead;
        vector<ListNode*> splitheads;
        for(int i=0;i<k;i++){
            if (head==NULL){
                splitheads.push_back(head);
            }
            else {
                Currlen=UsualSize+(Remaining-->0? 1:0);
                Pushhead=head;
                while(Currlen-->0 && head!=NULL){
                    prev=head;
                    head=head->next;
                }

                if(prev!=NULL){
                    prev->next=NULL;
                }

                splitheads.push_back(Pushhead);

            }


        }
        return splitheads;
        
    }
};

int main (){


    return 0;
}
