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
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long retval=-1;
        int l=0;
        while(l<n){
            int r=l;
            while(r+1<n && nums[r+1]==nums[l]){
                r++;
            }
            if(l==0 && r==n-1){
                return 0;
            }

            if(!(l==0&&r==0) && !(l==n-1&&r==n-1)){
                long long cost=(long long) (l+n-1-r)*nums[l];
                if(retval==-1||cost<retval){
                    retval=cost;
                }
            }

            l=r+1;
        }
        return retval;
    }
};

int main (){


    return 0;
}
