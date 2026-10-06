#include<iostream>
#include<cmath>

using namespace std ;

class Solution {
public:
    int countTriples(int n) {
        int count=0;

        // basic bruteforce approach 
        for (int a=1;a<=n;a++){
            for (int b=a;b<=n;b++){//i thought starting b from a i mean int b=a;b<=n;b++ as rescaning 
                // same value 2 time i mean lets take 1 2 3 so a , b if both start from 1 , one time it
                //  will check 1, 3 but again it will check 3 ,1 which will be same basically 

                int c2= (a*a)+(b*b);

                int c=sqrt(c2);// wait i will handle it even sqrt may be a float value 

                if(c*c==c2 && c<=n){
                    if(a==b){
                    count++;
                    }
                    else {
                        count+=2;
                    }
                }

            }
        }

        return count;
    }
};


int main (){

    
    return 0;
}