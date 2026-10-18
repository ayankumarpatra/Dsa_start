#include<iostream>
#include<stack>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // puttting all the elements in the unordered set
        unordered_set <int> us (nums.begin(),nums.end());

        int maxlen=0;

        //if any numbers prev number exist , it cant be the start of any sequence 
        // eg 2 3 4 9 ; here sequence cant be starrt with 3 ; but yes for 9 we have to check aagain 

        for (int currnum: us){
            if (us.find(currnum-1) == us.end()){ //  refer to top comments why 
                int currlen=1;

                while ( us.find( currnum+currlen ) != us.end()) // till the next element exist
                {
                    currlen++;
                }
                maxlen = max ( maxlen, currlen );
            }
        }

        return maxlen;
    }
};


int main (){

    
    return 0;
}