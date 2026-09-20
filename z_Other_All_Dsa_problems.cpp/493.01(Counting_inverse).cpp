#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

int merge(vector<int>&arr , int start,int mid, int end){
    vector<int> temp;

    int index1=start,index2=mid+1;

    while (index1<mid && index2<end)
    {
        if (arr[index1] < arr[index2]){}
    }
    
}

int mergesort(vector<int>&arr , int start, int end){
    if (start<end){
        int mid = start + (end-start)/2;

        int leftcount= mergesort(arr,start,mid);
        int rightcount= mergesort(arr,mid+1,end);

        int currinv = merge(arr,start,mid,end);

        return leftcount + rightcount + currinv;
    }
}


class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
        long long int count=0;

        return count;
    }
};


int main (){

    
    return 0;
}