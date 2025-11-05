#include<iostream>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<=k){
            return nums;
        }
        vector<int> MaxSlide;
        for(int i=0;i<nums.size()-k;i++){
            int j=i,limit=i+k,Tempi=i;
            while (j<limit)
            {
                if(nums[j]>nums[Tempi]){
                    Tempi=j;
                }
                j++;
            }
            if(Tempi<i+k){
                MaxSlide.push_back(nums[Tempi]);
            }
            else {
                MaxSlide.push_back(nums[i]);
            }
            
        }
        return MaxSlide;
        
    }
};


int main (){

    return 0;
}