#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        if (nums.size()==1){    return 1; }
        
        int min_val=INT_MAX,max_val=INT_MIN;

        int min_idx=0,max_idx=0;

        for (int i=0;i<nums.size();i++){
            if (nums[i]>max_val){
                max_val=nums[i];
                max_idx=i;
            }

            if (nums[i]<min_val){
                min_val=nums[i];
                min_idx=i;
            }
        }

        int global_min= min(min_idx,max_idx);
        int global_max= max(max_idx,min_idx);

        // now there are 3 possibilities to remove 
        /*
        case 1 : [0,-4,19,1,8,-2,-3,5] 
                    min max 
                so removing max automatically remove min 
                and remove both from front side

        case 2  remove both from back 
                [0,6,1,8,-4,19,-3,5] 
                        min max
        
        case 3  standard , removing from both ends 
                [0,-4,19,1,8,-2,200,5] 
                    min         max

        */
       return min ( min (global_max+1,(int) nums.size()-global_min), // case 1 , 2
                    (global_min +1 + (int) nums.size()-global_max) // case 3 
                   ); 
    }
};


int main (){

    
    return 0;
}