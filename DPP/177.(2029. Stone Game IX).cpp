#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        if (stones.size()==1 ){
            return false ;// bob wins as no stone remains
        }

        vector<int> count (3,0);

        for (int i=0 ;i<stones.size();i++){
            count[ (stones[i])%3 ]++;
        }

        // now the remainders have 3 possibilites 0 , 1 or 2 

        if (count[0]%2==0 ) {// count 0 is even 
            return ( count[1]!=0 && count[2]!=0 );
        }

        return (count[2] - count[1] >=3);
    }
};


int main (){

    
    return 0;
}