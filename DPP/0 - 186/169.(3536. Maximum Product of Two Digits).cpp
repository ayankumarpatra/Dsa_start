#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int maxProduct(int n) {
        
        int num1=INT_MIN,num2=INT_MIN;

        if (n>0){
            num1=n%10;
            n/=10;
        }
        if (n>0){
            num2=n%10;
            n/=10;
        }

        while (n>0)
        {
            int temp=n%10;
            if (num1<=temp){
                if (num2<=num1){
                    num2=num1;
                }
                num1=temp;
            }
        }
        
        return num1*num2;
    }
};

int main (){

    
    return 0;
}