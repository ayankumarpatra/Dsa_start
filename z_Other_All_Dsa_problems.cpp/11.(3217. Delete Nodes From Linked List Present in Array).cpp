#include<iostream>
#include<algorithm>
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

    bool ispresent (int val , const vector<int>& v){
        for (int i=0;i<v.size();i++){
            if (val==v[i]){
                return true;
            }
            if (val<v[i]){// as sorted 
                break;
            }
        }
        return false;
    }    

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        if (nums.size()>1){
            sort(nums.begin(),nums.end());
        }

        ListNode* mainhead=NULL;
    // getting first node;
        while (head!=NULL)
        {
            int temp=head->val;
            if (ispresent(temp,nums)){
                head=head->next;
                continue;
            }

            else{
                mainhead=head;
                break;
            }

            head=head->next;
        }

        if (mainhead==NULL){
            return NULL;
        }

        // connecting the other nodes 
        ListNode *connecthead=mainhead;
        while (head!=NULL)
        {
            int temp=head->val;
            if (ispresent(temp,nums)){
                head=head->next;
                continue;
            }

            else{
                connecthead->next=head;
                connecthead=connecthead->next;
            }
            head=head->next;
        }

        connecthead->next=NULL;
        
        return mainhead;

    }
};

int main (){


    return 0;
}


