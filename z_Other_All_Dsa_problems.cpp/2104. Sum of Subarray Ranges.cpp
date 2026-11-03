#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        if (nums.size()==0){
            return 0;
        }

        long long finalval ;

        int curr_min = nums[0], curr_max = nums[0];

        for (int j =0 ; j<nums.size()-1 ; j++){
            curr_min = nums[j], curr_max = nums[j];

            for ( int i = j+1 ; i < nums.size() ; i++ ){
                if ( nums [i] < curr_min ){
                    curr_min = nums[i];
                }

                else if ( nums [i] > curr_max){
                    curr_max = nums [i];
                }


                finalval += (curr_max - curr_min);
            }


            while (j<nums.size()-1 && nums [j] == nums [j+1] )
            {
                j++;
            }
            
        }

        return finalval;
    }
};


int main (){

    
    return 0;
}