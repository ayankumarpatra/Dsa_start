#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxKeep = 1;

        for(int i = 0; i < n; i++) {

            long long limit = 1LL * nums[i] * k;

            int j = upper_bound(nums.begin(), nums.end(), limit) - nums.begin();

            maxKeep = max(maxKeep, j - i);
        }

        return n - maxKeep;
    }
};


class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int j = 0, maxKeep = 1;

        for(int i = 0; i < n; i++) {

            while(j < n && 1LL * nums[j] <= 1LL * nums[i] * k)
                j++;

            maxKeep = max(maxKeep, j - i);
        }

        return n - maxKeep;
    }
};


int main (){

    
    return 0;
}