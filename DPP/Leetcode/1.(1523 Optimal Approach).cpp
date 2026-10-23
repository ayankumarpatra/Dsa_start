#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int countOdds(int low, int high) {
        int count=(high-low)/2;
        
        if(low%2!=0 || high%2!=0){
            count=count+1;
        } 

        return count;

    }

};


int main (){

    
    return 0;
}

