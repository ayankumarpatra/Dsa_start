#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
            int n = nums.size();
        vector<int> answer(n,0);
        
        int odds =0,evens =0;
        
        for (int i = n-1; i>=0; i--) {
            if (nums[i] % 2== 0) {
                answer[i] =odds;
                evens++;
            } else {
                answer[i]= evens;
                odds++;
            }
        }
    
        return answer;
    }    
};


int main (){

    
    return 0;
}