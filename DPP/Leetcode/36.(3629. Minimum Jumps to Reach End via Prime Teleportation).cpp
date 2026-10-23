#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:

    bool isprime (int n){
        if (n<2 || n%2==0){
            return false;
        }
        else if (n<4){
            return true;
        }

        for (int i=3;i<n/2;i+=2){// we can take sqrt n also 
            if (n%i==0){
                return false;
            }
        }

        return true;
    }


    int minJumps(vector<int>& nums) {
        int jump=0;

        bool jumped=false;

        for (int i=0;i<nums.size();i++){
            
            if (isprime(nums[i])){
                int startlast=nums.size()-1;

                while (startlast>i)
                {   if (nums[startlast]%(nums[i])==0){
                        i=startlast;
                        jumped=true;
                        break;
                    }
                    startlast--;
                }


                if (jumped){
                    return jump+(nums.size()-startlast-1);
                }
            }

            else jump++;
        }

        return jump;
    }
};


int main (){

    
    return 0;
}