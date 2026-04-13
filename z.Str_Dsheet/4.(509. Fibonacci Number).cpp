#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int fib_val(int n){
        if (n==0){
            return 0;
        }

        return n+fib_val(n-1);
    }
    int fib(int n) {
        n=fib_val(n);

        return n;
    }
};


int main (){

    
    return 0;
}