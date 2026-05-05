#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;


// //failed idea 

// will not work for 

// [31, 26, 33, 21, 40]
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         sort(stones.begin(),stones.end());

//         if (stones.size()==1){
//             return stones[0];
//         }

//         for (int i=stones.size()-1;i>=1;i--){
//             stones[i-1]=abs(stones[i-1]-stones[i]);
//         }

//         return stones[0];
//     }
// };



class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {

        if (stones.size()==1){
            return stones[0];
        }

        while (stones.size()!=1){
            int i=stones.size();
            stones[i-1]=abs(stones[i-1]-stones[i]);
            stones.pop_back();
            sort(stones.begin(),stones.end());
        }

        return stones[0];
        
    }
};


int main (){

    
    return 0;
}