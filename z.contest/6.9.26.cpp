#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    bool get_score(string s,int k){
        int count=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }
        }
        return count==k;
    }
    int countRotations(string s,int k){
        int n=s.size();
        int maxcount=0;
        for(int i=0;i<n;i++){
            if(get_score(s,k)){
                maxcount++;
            }
            s.insert(0,1,s.back());
            s.pop_back();
        }
        return maxcount;
    }
};


class Solution {
public:
    int countGoodRotations(vector<int>&nums){
        int n=nums.size();
        int k=n/2;
        int firsthalf_sum=0;
        int lasthalf_sum=0;
        for(int i=0;i<k;i++){
            firsthalf_sum+=nums[i];
        }
        for(int i=k;i<n;i++){
            lasthalf_sum+=nums[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(firsthalf_sum>lasthalf_sum){
                count++;
            }
            int leftelem=nums[i%n];
            int rightelem=nums[(i+k)%n];
            firsthalf_sum-=leftelem;
            firsthalf_sum+=rightelem;
            lasthalf_sum-=rightelem;
            lasthalf_sum+=leftelem;
        }
        return count;
    }
};




int main (){

    
    return 0;
}