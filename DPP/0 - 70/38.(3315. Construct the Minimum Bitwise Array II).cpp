#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


/*
base try version 


class Solution {
    public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ansvect;

        for (int currnum:nums){

        if (currnum & (currnum-1) ==0){
            ansvect.push_back(-1);
            continue;
            }
            
            int startval=(currnum/2)-1;// i observed from the examples that no ans value 
            // can become smaller than that the number /2 eg 30 not possible but 31 , its 15 means >(31/2)-1
            // 10 not possible but 11 its 9 eg >(11/2)=5 
            
            bool valnotfound=true;// just for saftey
            
            for (int i= startval;i<currnum;i++){
                if ( (i|(i+1)) == currnum ){
                    valnotfound=false;
                    ansvect.push_back(i);
                    break;
                }
            }
            
            if (valnotfound){// saftey if still val not found , put -1
            ansvect.push_back(-1);
        }
    }
    
    return ansvect;
}
};


but it passes 619 / 776 testcases passed so need to optimize more 
*/

class Solution {
    public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ansvect;

        for (int currnum:nums){

        if (currnum & (currnum-1) ==0 || (currnum & 1) == 0){
            ansvect.push_back(-1);
            continue;
            }
            
            int count = 0;
            int temp = currnum;
            while (temp & 1) {  // last bit is 1
                count++;
                temp >>= 1;  // right shift (divide by 2)
            }
            

            // removes the leftmost 1 from the rightmost group of 1s
            int result = currnum ^ (1 << (count - 1));
            
            ansvect.push_back(result);

    }
    
    return ansvect;
}
};

int main (){

    
    return 0;
}