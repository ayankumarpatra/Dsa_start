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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* front=head;
        ListNode* back=NULL;

        ListNode* temp=head;
        int sizee=0;

        while (temp!=NULL)
        {
            sizee++;
            temp=temp->next;
        }

        if (sizee!=0){
            k=k%sizee;
        }
        

        ListNode*currhead=head;
        while(k>0){
            bool check=false;
            while (front!=NULL && front->next!=NULL)
            {
                check=true;
                back=front;
                front=front->next;
            }
            if (check){
            back->next=NULL;
            front->next=currhead;
            currhead=front;
            }
            k--;
        }

        return currhead;
    }
};

int main (){


    return 0;
}
