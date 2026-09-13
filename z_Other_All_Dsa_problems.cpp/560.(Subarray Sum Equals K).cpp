#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0;
        // have to return the number of subarr only 

        // no brain standard brute force approach

        queue<int> q;

        int qsum=0;

        for (int i=0;i<nums.size();i++){

            qsum+=nums[i];
            q.push(nums[i]);

            if (qsum==k){
                count++;
            }

            while (qsum>k){
                qsum-=q.back();
                q.pop();
            }

            if (qsum<0){
                qsum=0;
            }
        }

        return count;

    }
};



int main (){

    
    return 0;
}