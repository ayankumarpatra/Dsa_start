#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if (start<nums.size() && nums[start]==target){
                return 0;
            }

        int maxlen=nums.size();

        for (int i=1;i<maxlen;i++ ){
            int forward=start+i,backward=start-i;

            if (forward<maxlen && nums[forward]==target){
                return i;
            }
            if (backward>-1 && nums[backward]==target){
                return i;
            }
        }
        // even q gurantee that it will be present sstill for saftey
        return -1;
    }
};


int main (){

    
    return 0;
}