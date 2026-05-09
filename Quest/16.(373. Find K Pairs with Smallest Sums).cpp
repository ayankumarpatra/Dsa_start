#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> returnvect;

        int pointer1=0,pointer2=0;

        while (returnvect.size()<k)
        {   vector<int> temp;
            if (pointer1<nums1.size()){
                temp.push_back(nums1[pointer1]);
                temp.push_back(nums2[pointer2]);
                returnvect.push_back(temp);

                if (pointer1+1<nums1.size()){
                    if (pointer2+1<nums2.size()){
                        if (nums1[pointer1+1]<nums2[pointer2+1]){
                            pointer1++;
                        }
                        else {
                            pointer2++;
                        }
                    }
                    else{
                        pointer1++;
                    }
                }
            }
            else if (pointer2<nums2.size()){
                pointer2++;
            }
            else{
                break;
            }
        }

        return returnvect;
        
    }
};


int main (){

    
    return 0;
}