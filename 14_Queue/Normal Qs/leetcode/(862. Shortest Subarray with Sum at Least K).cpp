#include<iostream>
#include<deque>
#include<vector>
#include<climits>

using namespace std ;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
    deque<int> q;

    int mainsize=nums.size();
    int minlen=INT_MAX;
    int sum=0,i=0;

    while (mainsize>0)
    {
        sum+=nums[i];

        if(sum<k){
            q.push_back(nums[i]);
            i++;
        }
        else if(sum>=k){
            q.push_back(nums[i]);
            i++;
            break;
        }

    }
    
    i<minlen? minlen=i:minlen;

    for(i;i<mainsize;i++){
        for(int j=0;j<mainsize;j++){
            
        }
    }

    }
};


int main (){

    
    return 0;
}