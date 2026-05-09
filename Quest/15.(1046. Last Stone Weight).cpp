#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;



class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {

        if (stones.size()==1){
            return stones[0];
        }
        sort(stones.begin(),stones.end());

        while (stones.size()!=1){
            int i=stones.size()-1;
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