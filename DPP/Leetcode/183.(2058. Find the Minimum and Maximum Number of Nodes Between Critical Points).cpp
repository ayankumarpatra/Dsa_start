#include<iostream>
#include<climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> maxmin_idx;

        vector<int> returnvect;

        ListNode*back = head;
        head=head->next;

        if (head==NULL || head->next==NULL){
            returnvect.push_back(-1);
            returnvect.push_back(-1);

            return returnvect;
        }
        
        ListNode* front=head->next;
        
        int i=2;
        while (front!=NULL)
        {
            if ( back->val < head->val && head->val > front->val){
                maxmin_idx.push_back(i);
            }
            else if (  back->val > head->val && head->val < front->val){
                maxmin_idx.push_back(i);
            }


            back=head;
            head=front;
            front=front->next;
            i++;
        }
        
        if (maxmin_idx.size()==0){
            returnvect.push_back(-1);
            returnvect.push_back(-1);
            
            return returnvect;        
        }
        if (maxmin_idx.size()<2){
            returnvect.push_back(maxmin_idx[0]);
            returnvect.push_back(maxmin_idx[0]);
            
            return returnvect;        
        }
        
        // now finding min diff 

        int mindiff=INT_MAX;

        for (int i=0;i<maxmin_idx.size()-1;i++){
            if (maxmin_idx[i+1] - maxmin_idx[i] <mindiff){
                mindiff=maxmin_idx[i+1] - maxmin_idx[i];
            }
        }

        returnvect.push_back(mindiff);
        returnvect.push_back( maxmin_idx[maxmin_idx.size()-1] - maxmin_idx[0] );
        
        return returnvect;
        
        
    }
};

int main (){
    
    
    return 0;
}
