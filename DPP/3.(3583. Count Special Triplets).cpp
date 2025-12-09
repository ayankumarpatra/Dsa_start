#include<iostream>
#include<vector>

#include<unordered_map>
using namespace std ;




/*
basic bruteforce approach ,

just go through once , you will understand 

 
class Solution {
public:
    int specialTriplets(vector<int>& nums) {

        int maxlen=nums.size(),totalcount=0;

        for (int i=1;i<maxlen-1;i++){// index 0 and maxlen cant be a mid pos
            // so just excluding them , saving a microsec time 

            long long TargetElement=nums[i]*2;
            int leftcount=0,rightcount=0;
            int leftcurrent=i-1,rightcurrent=i+1;
            bool leftbreak=false,rightbreak=false;

            while (1)
            {   
                // first counting left part
                if(!leftbreak){
                    if(nums[leftcurrent]==TargetElement){
                        leftcount++;
                    }
                    leftcurrent--;
                    if(leftcurrent<0){
                        leftbreak=true;
                    }
                }

                // counting right 

                if(!rightbreak){
                    if(nums[rightcurrent]==TargetElement){
                        rightcount++;
                    }
                    rightcurrent++;
                    if(rightcurrent==maxlen){
                        rightbreak=true;
                    }
                    
                } 


                if(leftbreak && rightbreak){// break if leftbreak and rightbreak both got true
                    break;
                }

            }

            totalcount+=(leftcount*rightcount);
            

        }
        
        return totalcount;
    }
};



*/

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long,int> leftFreq,rightFreq;
        const long long MOD = 1000000007;
        // filling right side freq

        for(long long element : nums){
            rightFreq[element]++;
        }

        int totalcount=0;

        for(int i=0;i<nums.size();i++){
            rightFreq[nums[i]]--;
        

        long long target =2*nums[i];

        int leftcount=leftFreq[target];
        int rightcount=rightFreq[target];

        totalcount+=(leftcount*rightcount);

        // Now the ith index num will be a part of left side 

        leftFreq[nums[i]]++;

        }

        return totalcount;
    }
};