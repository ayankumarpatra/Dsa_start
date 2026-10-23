#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        vector<int> arr1;
        vector<int> arr2;

        int i=0;

        // q gurantee constrains of atleast 3 elements
        arr1.push_back(nums[i++]);
        arr2.push_back(nums[i++]);

        for (i ; i<nums.size();i++){
            /*
            If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1
            */

            if (arr1[arr1.size()-1] > arr2[arr2.size()-1]){
                arr1.push_back(nums[i]);
            }

            else{
                arr2.push_back(nums[i]);
            }
        }

        arr1.reserve(arr1.size()+arr2.size());

        arr1.insert(arr1.end(),arr2.begin(),arr2.end());

        return arr1;
    }
};

int main (){

    
    return 0;
}