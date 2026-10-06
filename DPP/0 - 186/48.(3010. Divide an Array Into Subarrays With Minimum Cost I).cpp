#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
    // as constrains already say 3 <= n <= 50 so not using the 0 case ;

    int val1,val2,val3;

    int i=0,maxidx=nums.size();

    val1=(nums[i++]);
    val2=(nums[i++]);
    val3=(nums[i++]);

    for (i;i<maxidx;i++){
        
        // if (nums[i]<val1[0]){
        //     val1[0]=nums[i];
        // }
       if (nums[i]<val3){
            if (val2>val3){
                val2=val3;
            }
            val3=nums[i];
        }
        else if (nums[i]<val2){
            val2=nums[i];
        }

    }

    return(val1+val2+val3);
    }
};


// alternate idea

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a=nums[0];
        sort(nums.begin()+1,nums.end());
        int b=nums[1];
        int c=nums[2];
        return a+b+c;       
    }
};


int main (){

    
    return 0;
}