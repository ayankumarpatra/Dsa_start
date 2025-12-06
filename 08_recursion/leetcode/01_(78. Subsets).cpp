#include<iostream>
#include<vector>

using namespace std ;

class Solution {
public:
    
    void Subset_generator(vector<int>& mainset,vector<int>& helper, vector<vector<int>>& ans,int i){
        if(i==mainset.size()){
            ans.push_back(helper);
            return;
        }
        // include the current element

        helper.push_back(mainset[i]);
        Subset_generator(mainset,helper,ans,i+1);

        // removing the elemnt 
        helper.pop_back();
        Subset_generator(mainset,helper,ans,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> helper;
        Subset_generator(nums,helper,ans,0);
        return ans;
    }
};


int main (){

    
    return 0;
}