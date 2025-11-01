// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points


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
        ListNode *prev=head;
        ListNode *curr=head->next;

        vector<int> Returnvector(2,-1);
        vector<int> criticalpoints;

        int i=1;

        while (curr!=NULL && curr->next!=NULL)
        {
            if((curr->val > prev-> val && curr->val>curr->next->val)||(curr->val < prev-> val && curr->val<curr->next->val)){
                criticalpoints.push_back(i);
            }
            prev=curr;
            curr=curr->next;
            i++;

        }

        

        if(criticalpoints.size()<2){
            Returnvector[0]=(-1);
            Returnvector[1]=(-1);
        }
        else {
            int MinDist=INT_MAX;
            int MaxDist=criticalpoints.back()-criticalpoints.front();
            int Ems=criticalpoints.size();
            for(int i=1;i<Ems;i++){
                MinDist=min(MinDist,(criticalpoints[i]-criticalpoints[i-1]));
                
            }
            
            Returnvector[0]=(MinDist);
            Returnvector[1]=(MaxDist);

        }
        
        
        return Returnvector ;

    }
};


int main (){


    return 0;
}
