#include<iostream>
#include<stack>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    // for loop + recursive approach 

    int n;
    unordered_set<int> st;

    void helper (vector<int> &temp , vector<vector<int>>& returnvect ,const vector<int>& nums){
        // if the curr temp size is equal to n , means we have made a permutation and we can push to it 

        if ( temp.size()==n){
            returnvect.push_back(temp);
            return;
        }


        for (int i=0;i<n;i++){
            if (st.find(nums[i])==st.end()){// if the current element not in set 

                // if taking the current element 
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                helper(temp,returnvect,nums);

                // Backtrack: undo the current choice
                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> temp;
        vector<vector<int>>returnvect;

        n=nums.size();

        helper(temp,returnvect,nums);
        
        return returnvect;
    }
};


int main (){

    
    return 0;
}