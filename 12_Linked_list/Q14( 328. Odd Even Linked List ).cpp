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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* CurrHead=head;
        if(CurrHead==NULL || CurrHead->next==NULL){return CurrHead;}
        ListNode* Lefthead=CurrHead;
        ListNode* Mainleft=Lefthead;
        CurrHead=CurrHead->next;
        ListNode* Righthead=CurrHead;
        ListNode* ConnectRight=Righthead;
        CurrHead=CurrHead->next;
        for(int i=3;i && CurrHead!=NULL ;i++){
            if(i%2!=0){
                Lefthead->next=CurrHead;
                Lefthead=CurrHead;
            }
            else if(i%2==0){
                Righthead->next=CurrHead;
                Righthead=CurrHead;
            }
            CurrHead=CurrHead->next;
        }
        Righthead->next=NULL;
        Lefthead->next=ConnectRight;

        return Mainleft;

    }
};


// self try later 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
            if (head == NULL){
                return NULL;
            }
        ListNode* oddhead = head;
            head = head->next;

            if (head == NULL){
                return head;
            }

        ListNode* evenhead = head ;
            head = head->next;

        ListNode* currodd = oddhead;
        ListNode* curreven = evenhead;
        
        int i= 1;

        while ( head!=NULL )
        {
            if (i&1){
                currodd->next=head;
                currodd = currodd->next;
            }
            else {
                curreven->next=head;
                curreven = curreven->next;
            }
        }
        
        currodd->next = evenhead;
        
        curreven->next = NULL;

        return oddhead;
        
    }
};

int main (){


    return 0;
}
