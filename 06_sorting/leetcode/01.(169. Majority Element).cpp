#include<iostream>
#include<climits>
#include<vector>

using namespace std ;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxval=INT_MIN,count=0,aim=nums.size()/2;
        for(int val:nums){
            int currval=val;
            count=0;
            for (int val2:nums){
                if (val2==currval){
                    count++;
                }
            }
            if(count>=aim){
                return currval;
                break;
            }
        }
    }
};

// optimized soln 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentElement = 0;
        int count = 0;

        for (int num : nums) {

            // if count becomes 0, choose new candidate
            if (count == 0) {
                currentElement = num;
                count = 1;
            }
            else {
                // increase or decrease vote
                if (num == currentElement)
                    count++;
                else
                    count--;
            }
        }

        return currentElement;
    }
};

/*
working becuase 

because the majority element appears more than half the time

it will always have more “votes” than all other elements combined

any time we pair it against a different element, the count might drop, but overall it will remain at the end.
*/


int main (){

    
    return 0;
}