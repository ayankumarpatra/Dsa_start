#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        if(low==high){
            if(low%2==0){
                return 0;
            }
            else {
                return 1;
            }
        }
        if(low%2==0){
            if(low+1<=high){
                low=low+1;
            }
        }
        while (low<=high)
        {
        count++;
        low+=2;
        if(low<=high){
            count++;
            low+=2;
        }
        }
        return count;

    }

};


int main (){

    
    return 0;
}