#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int point1max=nums1.size(),point2max=nums2.size();
        int point1=0,point2=0;

        while (point1<point1max && point2<point2max)
        {
            if (nums1[point1]==nums2[point2]){
                return nums1[point1];
            }

            else if(nums1[point1]>nums2[point2]){
                point2++;
            }
            else{
                point1++;
            }
        }
        return -1;
        
    }
};


int main (){

    
    return 0;
}