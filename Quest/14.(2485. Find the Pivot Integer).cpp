#include<iostream>
#include<cmath>
#include<vector>

using namespace std ;


int pivotInteger(int n) {
    int totalSum = n * (n + 1) / 2;
    int leftSum = 0;
    
    for (int i = 1; i <= n; i++) {
        leftSum += i;
        // rightSum includes i, so it's totalSum - (sum before i)
        int rightSum = totalSum - leftSum + i; 
        
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}


class Solution {
public:
    int pivotInteger(int n) {
        int totalsum=n*(n+1)/2;

        int temp=sqrt(totalsum);

        if (temp*temp==totalsum){
            return temp;
        }

        return -1;
    }
};

int main (){

    
    return 0;
}