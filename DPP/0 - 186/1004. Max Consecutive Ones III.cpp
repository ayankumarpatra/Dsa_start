#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        queue<int> q;
        int curr_zero=0,max_len=0;
        
        for (int i=0;i<nums.size();i++){
            if (nums[i]==1){
                q.push(1); // if the curr number is 1 , directly psh int queue 
            }

            else{
                /*
                if the number is 0 , there will be 2 cases either we have available limit to convert it
                to 1 or not 
                */

                // case 1 limit available to convert , in that case , push only

                if (curr_zero<k && k>0){
                    q.push(0);
                    curr_zero++;
                }

                // case 2 limit not available , so have to pop till queue become empty or we get a 0
                else{
                    while (q.size()>0 && q.front()==1)
                    {
                        q.pop();
                    }

                    if (q.size()>0){
                        q.pop();
                        curr_zero--;
                    }

                    // one more thing , we cant push the curr zero , if the limit is 0 only 

                    if (curr_zero<k && k>0){
                        q.push(0);
                        curr_zero++;
                    }
                }
                
            }

            max_len = max (max_len , (int) q.size());
        }
        

        return max_len;
    }
};


int main (){

    
    return 0;
}