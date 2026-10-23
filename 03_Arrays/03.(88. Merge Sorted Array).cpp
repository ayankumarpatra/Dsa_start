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

// retry 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // m = elements in num 1 n n = element in num 2 

        // both are sorted in ascending order ;
        // so here we will just put the elements 1 by 1 but from last in nums 1 
        // as nums size is m +n 

        int point_1=m-1, point_2=n-1;
        int point_main=m+n-1;

        while ( point_2>=0 ) // till the 2nd vector got empty as both are sorted 
        // so when we merge till the 2nd vector , remaining will be sorted 
        {
            if ( point_1 >=0 && nums1[point_1]>nums2[point_2]){
                nums1[point_main --]=nums1[point_1--];
            }
            else{
                nums1[point_main --]=nums2[point_2--];
            }
        }
        
    }
};


int main (){

    
    return 0;
}