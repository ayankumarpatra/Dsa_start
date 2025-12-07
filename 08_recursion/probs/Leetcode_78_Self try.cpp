#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    void Subset_Generator(vector<int> &mainset, vector<int> &helper, vector<vector<int>> &Subset , int i=0){
        if(i==mainset.size()){
            Subset.push_back(helper);
            return;      
        }

        // adding curr element
        helper.push_back(mainset[i]);
        Subset_Generator(mainset,helper,Subset,i+1);
        // adding element but removing the last added element
        helper.pop_back();
        Subset_Generator(mainset,helper,Subset,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>subsets;
        vector<int> helper;

        Subset_Generator(nums,helper,subsets,0);

        return subsets;
        
    }
};


int main (){

    
    return 0;
}