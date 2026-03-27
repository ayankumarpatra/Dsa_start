#include<iostream>
#include<vector>
#include<string>

using namespace std ;

class Solution {
public:
    int numberOfWays(string corridor) {

        vector<int> Seat_Pos;
        int PLants_Count=0;

        for (int i=0;i<corridor.length();i++){
            if(corridor[i]=='S'){
                Seat_Pos.push_back(i);
            }
        }

        // now if 1. total sets is =0 or %2!=0  we cant make a pair 
        if (Seat_Pos.size()==0 || Seat_Pos.size()%2!=0){
            return 0;
        }

        // calculating ways 

        long long ways =1;

        int MOD=1e9+7;

        // moving 2 pos at a time as we need pairs eg pair 1 id index 0 ,1 
        // starting at idx 1 as first pair end at 1 , then increase it by 2 each time 

        for (int i=1;i<Seat_Pos.size()-1;i+=2){
            //End of the prev pair 

            int EndofPrevPair=Seat_Pos[i];

            // start of the next pair
            int NextPairStart=Seat_Pos[i+1];

            // in bth the 2 i mean last group end and first group start theres plants only 
            ways=(ways*(NextPairStart-EndofPrevPair))%MOD;
        }

        return (int)ways%MOD;
    }
};


int main (){

    
    return 0;
}