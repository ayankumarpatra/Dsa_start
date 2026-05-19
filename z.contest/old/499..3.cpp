#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long total_operations = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            
            if (nums[i] > nums[i + 1]) {
                total_operations += (nums[i] - nums[i + 1]);
            }
        }
        
        return total_operations;
    }
};

int main (){

    
    return 0;
}