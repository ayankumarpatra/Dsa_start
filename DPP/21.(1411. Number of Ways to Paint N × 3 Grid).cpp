#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int numOfWays(int n) {
        long long MOD=1e9+7;

        long long aba=6;
        long long abc=6;

        for (int i=2;i<=n;i++){
            long long newaba= (aba*3 +abc*2)%MOD;
            long long newabc= (aba*2 +abc*2)%MOD;

            aba=newaba;
            abc=newabc;

        }
        return (aba+abc)%MOD;
    }
};


int main (){

    
    return 0;
}