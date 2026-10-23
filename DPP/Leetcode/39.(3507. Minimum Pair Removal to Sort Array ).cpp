#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

/*

self try , failed after some testcases due to tle ...

so will have to optimize it 


class Solution {
public:
int minimumPairRemoval(vector<int>& nums) {
    // as the q asked to "If multiple such pairs exist, choose the leftmost one."
    // making with respect of the leftmost one 
    
    int operationcount=0,numlen=nums.size();
    
    for (int i=0;i<numlen-1;i++){
        
    int nextindex=-1,currindex=-1;
    
    bool firstnotdone=true;
    
    for (int j=i;j<numlen-1;j++){
        // setting the current and next indexes
        if (nums[j]!=-9999){// using 9999 as q constrains says that -1000 <= nums[i] <= 1000
        if (firstnotdone){
            currindex=j;
            firstnotdone=false;
        }
        else {
            nextindex=j;
            i=j;
            break;
        }
    }
}

if (nextindex==-1){
    break;
}

            if (nums[currindex]>nums[nextindex]){
                
                while (nums[currindex]>nums[nextindex])
                {
                    
                int tempnext=i;    
                for (int j=i;j<numlen-1;j++){
                    // setting the temp next indexes
                    if (nums[j]!=-9999){
                        tempnext=j;
                        i=j;
                        break;
                    }
                }
                
                nums[nextindex]=nums[nextindex]+nums[tempnext];
                operationcount++;
            }
            
        }
        
    }
    
    return operationcount;
}
};

*/

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        auto issorted = [&]() {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1])
                    return false;
            }
            return true;
        };

        while (!issorted()) {

            int minSum = INT_MAX;
            int index = 0;

            for (int i = 0; i < nums.size() - 1; i++) {
                int currSum = nums[i] + nums[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    index = i;
                }
            }

            nums[index] = nums[index] + nums[index + 1];

            nums.erase(nums.begin() + index + 1);
            operations++;
        }

        return operations;
    }
};



int main (){

    
    return 0;
}