#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int totalxor=0,n=nums.size();

        bool gotpositive=false;

        for (auto currnum:nums){
            
            gotpositive= gotpositive || (currnum>0);// if once get a +ve num ,true forever

            totalxor^=currnum;
        }

        if (totalxor!=0){ return n; }
        if (gotpositive){ return n-1; } /*
        xor means sim term =0 eg 1 ^1 = 0 ^ 0 = 0 

            its the trickiest part to understand , see if 3 numbers xor=0 , removing any 1 num will be the 
            xor value of the remaining 2 
            eg see 1 2 3 :   1^ 2^3 =0 ( 1= 0 0 1
                                         2= 0 1 0
                                    xor =   0 1 1 =3 
                and its valid for any number series till a^b^c =0 
                so if we remove the non zero number the xor value of remaining will be the same 

                so length -1 ;
            )
        */

        return 0; // all elements are 0 , we didnt get any +ve num 
    }
};


int main (){

    
    return 0;
}