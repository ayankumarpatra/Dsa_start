#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr=n&1;
        while(n){
            if (curr==(n&1)) {
                curr=1-curr;
            }
            else return false;
            n=n>>1;
        }
        return true;
    }
};


int main (){

    
    return 0;
}