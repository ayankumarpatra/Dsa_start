#include<iostream>
#include<climits>
#include<vector>

using namespace std ;

// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int maxval=INT_MIN;
//         for (int j=0;j<nums2.size();j++){
//             for (int i=0;i<=j && i<nums1.size();i++){
//                 if (nums1[i] <= nums2[j]){
//                     int temp=j-i;
//                     maxval=max(minval,temp);
//                 }
//             }
//         }

//         if (maxval!=INT_MAX){
//             return maxval;
//         }
//         else return 0;
//     }
// };

// failed first approach ... need to optimize it 


class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,maxdist=0;
        while (i < nums1.size() && j<nums2.size())
        {
            
            if (nums1[i] <= nums2[j]){
                maxdist=max(maxdist,abs(j-i));
                j++;
            }
            
            else {
                i++;
                j=max(i,j);
            }
        }

        return maxdist;
        
    }
};


int main (){

    
    return 0;
}