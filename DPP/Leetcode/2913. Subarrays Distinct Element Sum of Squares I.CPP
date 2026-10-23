#include<iostream>
#include<stack>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int count =0 , n = nums.size();

        for (int i=0;i<n;i++){
            unordered_set<int> us;

            for (int j=i;j<n;j++){
                us.insert(nums[j]); // insert the current element
                // as the set willnt contain duplicate so we can directly square and add 
                count += us.size()*us.size();
            }
        }

        return count;
    }
};



int main (){

    
    return 0;
}