#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    void Generation_Helper(vector<int> &mainset,vector<int> &helper,vector<vector<int>> &subset,int i=0){
        //basecase 
        if(i==mainset.size()){
            subset.push_back(helper);
            return;
        }
        // adding the current element
        helper.push_back(mainset[i]);
        Generation_Helper(mainset,helper,subset,i+1);

                // removing the last added element
        helper.pop_back();

        // removing element till the duplicates present 
        while (i+1<mainset.size() && mainset[i]==mainset[i+1]){
            i++;
        }
        Generation_Helper(mainset,helper,subset,i+1);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> helper;
        vector<vector<int>> subset;

        sort(nums.begin(),nums.end());

        Generation_Helper(nums,helper,subset,0);

        return subset;
    }
};

int main (){

    
    return 0;
}