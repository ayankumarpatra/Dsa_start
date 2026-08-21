#include<iostream>
#include<unordered_set>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> returnvect;

        int point1=0,point2=0;
        int val1=-1,val2=-1;

        while (point1<nums1.size() && point2<nums2.size())
        {
            val1=nums1[point1];
            val2=nums2[point2];

            if (val1==val2){
                if (returnvect.empty() || returnvect[returnvect.size()-1]!=val1){
                    returnvect.push_back(val1);
                }
                point1++;
                point2++;
            }

            else if (val1>val2){
                point2++;
            }
            else{
                point1++;
            }
        }
        
        return returnvect;
    }
};



int main (){

    
    return 0;
}