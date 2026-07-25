#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        int val = 0;
        for (int num : nums) {
            val |= num;
        }

        return val + 1;
    }
};


int main (){

    
    return 0;
}