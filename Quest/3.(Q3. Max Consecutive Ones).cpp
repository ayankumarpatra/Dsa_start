#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcons=0,maxlen=nums.size();
        if (maxlen==1){
            if (nums[0]==0){
                return 0;
            }
            else {
                return 1;
            }
        }
        for (int i=0;i<maxlen;i++){
            int tempcount=0;

            while (i<maxlen && nums[i]==1)
            {
                tempcount++;
                i++;
            }

            maxcons=max(maxcons,tempcount);        
        }

        return maxcons;
    }
};


int main (){

    
    return 0;
}