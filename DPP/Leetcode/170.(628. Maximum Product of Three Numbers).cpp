#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size();
        return max (
            nums[0]*nums[1]*nums[2],
            nums[i-1]*nums[i-2]*nums[i-3]
        );
    }
};

int main (){

    
    return 0;
}