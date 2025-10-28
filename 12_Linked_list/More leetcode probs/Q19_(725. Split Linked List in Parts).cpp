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
        ListNode *curr=head;
        while (curr!=NULL)
        {
        curr=curr->next;
        length++;
        }
        int Firstpart,Restpart,Partsize;
        if (length<k){
            Firstpart=Restpart=1;
        }
        else if(length%k==0){
            Firstpart=Restpart=length/k;
        }
        else {
            Firstpart=length/k+1;
            Restpart=length/k;
        }
        // not maintaining head , else we can maintain head by using a curr pointer 
        vector<ListNode*> Splitheads;
        ListNode * temp;
        ListNode * Pushhead;

        for(int i=0;i<k;i++)
        {
            if(head==NULL){
                Splitheads.push_back(NULL);
            }
            else{
                    Pushhead=head;
                    if(i<(length%k)){
                        Partsize=Firstpart;
                    }
                    else {
                        Partsize=Restpart;
                    }

                    for(int j=0;j<Partsize;j++){
                        temp=head;
                        head=head->next;
                    }

                    if(temp!=NULL){
                        temp->next=NULL;
                    }

                    Splitheads.push_back(Pushhead);
                }
            }
        return Splitheads;

    }
};

int main (){


    return 0;
}
