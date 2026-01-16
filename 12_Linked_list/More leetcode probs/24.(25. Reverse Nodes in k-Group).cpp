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

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temphead=head;

        ListNode* travarse=head;

        bool lastCantReverse=false;
        // becuase there will be max 1 listnode <k len that cant be reversed
        bool revhead=false;// as after the first ever reversal head will change 

        

        while (travarse!=NULL)
        {
            // first check if travarsal possible 
            ListNode *front=travarse;
            ListNode * rear=travarse->next;
            if (rear ==NULL || rear->next==NULL){
                return;
            }
            ListNode * afterrear=rear->next;

            for (int i=0;i<k && front!=NULL && rear!=NULL;i++){
                travarse=afterrear;

                rear->next=front;
                front=rear;
                rear=afterrear;
                afterrear=afterrear->next;

                if(i<4 && rear==NULL){
                    break;
                    lastCantReverse=true;
                }
            }

            if (
                lastCantReverse
            )
        }
        
    }
};

int main (){


    return 0;
}
