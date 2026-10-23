#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count=0;
        long long templen=1; // length of atleast 1 smooth decent 

        for (int i=1;i<prices.size();i++){
            if (prices[i]==prices[i-1]-1){
                templen++;// extend the current seq
            }

            else {
                count+=(templen*(templen+1)/2);
                templen=1;// reset templen 
            }
        }

        // int slow=0,fast=1;

        // while (fast<prices.size())
        // {
        //     if (prices[fast]==prices[slow]-1){
        //         count++;
        //     }
        //     // first case if only 2 continious element is there 
        //     // this temp case to solve if continious elements are there
        //     /*
        //         eg if 321 there 
        //         this code only identifies 3 2 ; 2 1 ;   cant determine 321 
        //     */
        //    int tempfast =fast,tempslow=slow;

        //    bool flag=false;

        //     while (tempfast<prices.size() && ((prices[tempfast])==prices[tempslow]-1))
        //     {
        //         flag = true;
        //         tempfast++;
        //         tempslow++;
        //     }
            
        //     if (flag){
        //         flag=false;
        //         count++;
        //     }

        //     fast+=1;
        //     slow+=1;
        // }



        // adding the last seq 
        count+=(templen*(templen+1)/2);
        return count;;
        
    }
};


int main (){

    
    return 0;
}