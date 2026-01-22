#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> returnvector;
        for (int i=0;i<=n;i++){
            returnvector.push_back(nums[i]);// pushing xi
            returnvector.push_back(nums[n+i+1]);// pushing yi
        }
        return returnvector;
    }
};


int main (){

    
    return 0;
}