#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalsum=0;

        for (int num : nums){
            int count=0;
            int currentsum=0;

        // checking upto sqrt of fhte num

        for ( int i=1;i*i<=num;++i){
            if (num%i==0){
                if (i*i==num){
                    count++;
                    currentsum+=i;
                }
                else{
                    count+=2;
                    currentsum+=i+(num/i);
                }
            }
            if (count>4){
                break;
            }
        }
            if (count==4){
                totalsum+=currentsum;
            }
        }
    return totalsum;
    }
};


int main (){

    
    return 0;
}