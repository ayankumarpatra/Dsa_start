#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort (nums.begin(),nums.end());

        for (int i =0 ; i<nums.size();i++){
            if (nums[i]!=0){
                if (nums[i] == nums.size() - i -1){
                    return nums[i];
                }
            }
        }

        return -1;
    }
};

int main (){

    
    return 0;
}