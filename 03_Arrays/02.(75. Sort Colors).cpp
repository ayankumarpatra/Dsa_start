#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

int partition(vector<int> &arr,int lower_bound,int Upper_bound){
    int pivot=arr[lower_bound];
    int start=lower_bound,end=Upper_bound;

    while (start<end)
    {
        while (start<=Upper_bound && arr[start]<=pivot )
        {
            start++;
        }
        
        while (end>lower_bound && arr[end]>pivot )
        {
            end--;
        }
        
        if (start<end){
            swap(arr[start],arr[end]);
        }
    }

    swap(arr[lower_bound],arr[end]);
    return end;
}


void quicksort(vector<int> &arr,int lower_bound,int Upper_bound){
    if(lower_bound<Upper_bound){
        int pos=partition(arr,lower_bound,Upper_bound);
        quicksort(arr,lower_bound,pos-1);
        quicksort(arr,pos+1,Upper_bound);
    }
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
    }
};


int main (){

    
    return 0;
}