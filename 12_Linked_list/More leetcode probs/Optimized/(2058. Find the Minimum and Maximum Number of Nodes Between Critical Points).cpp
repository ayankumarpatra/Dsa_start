#include<iostream>
#include<vector>
#include<climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        bool firsttime=true;
        int i,firstindex,previndex,minindex=INT_MAX;
        ListNode*prev=head;
        head=head->next;

        for(i=1;head!=NULL && head->next!=NULL ;i++){
            if((prev->val<head->val && head->val>head->next->val) || (prev->val>head->val && head->val<head->next->val)){
                if(firsttime){
                    firstindex=previndex=i;
                    firsttime=false;
                }
                else {
                    minindex=(minindex<(i-previndex))?minindex:i-previndex-1;
                    previndex=i;
                }          
            }
            prev=head;
            head=head->next;

        }

        if(minindex!=INT_MAX){
            return {minindex,(previndex-firstindex)};
        }
        else{
            return {-1,-1};
        }      
    }
};


int main (){


    return 0;
}
