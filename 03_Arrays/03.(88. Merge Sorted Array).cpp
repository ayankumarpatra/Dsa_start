#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> returnvect;

        int vect_1pointer=0,vect_2pointer=0;

        while ((vect_1pointer<nums1.size()) && (vect_2pointer<nums2.size()))
        {
            if(m>0 && nums1[vect_1pointer]<=nums2[vect_2pointer]){
                returnvect.push_back(nums1[vect_1pointer++]);
                m--;
            }
            else if (n>0 && nums1[vect_1pointer]>nums2[vect_2pointer]){
                returnvect.push_back(nums2[vect_2pointer++]); 
                n-- ;           
            }

            if (m==0||n==0){
                break;
            }
        }

        while (m>0 && vect_1pointer<nums1.size())
        {
            returnvect.push_back(nums1[vect_1pointer++]);
            m--;
            if(m==0){
                break;
            }
        }
        while (n>0 && vect_2pointer<nums2.size())
        {
            returnvect.push_back(nums2[vect_2pointer++]);
            n--;
            if(n==0){
                break;
            }
        }
        
        nums1=returnvect;     
    }
};


int main (){

    
    return 0;
}