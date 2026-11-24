#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include <numeric> // for gcd

using namespace std ;



class Solution {
public:
        int maxLength(vector<int>& nums) {
        int maxlen =2 ;
        /* q said that min length is 2 so obv that min 2 length str we will get 
         1. if 2 num are co prime , then lcm =1 ; prod = gcd * lcm => prod = gcd 
         2.  if both the number are not coprime eg 4 and 8. So in that case for 4 and 8 the GCD will be 4 and LCM will be 8. So then the product of 4 and 8 is 32 and here GCD is 4 and LCM and 8 so obviously multiplying them you will get the same 32.
         */
        int n = nums.size();
        
        for (int left =0 ; left <n ; left ++){ //  fix the left end and extend the right end 

            int product =nums[left] , curr_gcd = nums[left] , curr_lcm = nums[left] ;

            for (int right = left +1 ; right<n ; right ++){
                curr_gcd = gcd(curr_gcd, nums[right]);
                curr_lcm = lcm(curr_lcm,nums[right]);
                if (__builtin_mul_overflow(product, nums[right], &product)) {
                    break;
                }

                if (product==curr_gcd*curr_lcm){
                    maxlen = max (maxlen , right-left+1 );
                }
            }

        }

        return maxlen;
    }
};

int main (){

    
    return 0;
}