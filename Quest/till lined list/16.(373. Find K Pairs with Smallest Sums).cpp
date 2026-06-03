#include<iostream>
#include<stack>
#include<vector>

using namespace std ;


// approach 2

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int pointer1=0,pointer2=0;

        vector<vector<int>> retunvect;

        while (retunvect.size()<k)
        {
            vector<int> temp;
            temp.push_back(nums1[pointer1]);
            temp.push_back(nums2[pointer2]);

            retunvect.push_back(temp);

            if(pointer1+1<nums1.size() && nums1[pointer1+1]<nums2[pointer2+1]){
                pointer1++;
            }
            else if (pointer2+1<nums2.size()){
                pointer2++;
            }
            else{
                break;// shouldnt happen still just for saftey
            }
        }

        return retunvect;
        
    }
};


int main (){

    
    return 0;
}