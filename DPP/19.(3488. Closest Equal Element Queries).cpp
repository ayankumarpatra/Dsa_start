#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std ;

class Solution {
public:
    int binsearch(vector <int> &arr, int l, int h, int &key){
        int m = floor((l+h)/2);
        if(arr[m] == key)return m;
        if(key<arr[m]) return binsearch(arr, l, m-1, key);
        else return binsearch(arr, m+1, h, key);
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res;
        int n = nums.size();
        unordered_map <int, vector <int>>H;
        for(int i =0; i<nums.size(); i++){
            H[nums[i]].push_back(i);
        }
        for(int q: queries){
            int num = nums[q];
            vector <int> &indexes = H[num]; // Reference to avoid copy (reduces the time complexity)
            int m = indexes.size();

            // Find position using binary search
            int i = binsearch(indexes, 0, m-1, q);
            int dist = -1;

            // calculate circular neighbors
            int left = (i+(m-1))%m;
            int right = (i+1)%m;
            if(!(m==1)){
                dist = min(abs(q-indexes[left]), abs(q-indexes[right])); // non-circular left and right distance 
                dist = min(abs(n-q+indexes[right]), dist); // circular right distance
                dist = min(abs(q+n-indexes[left]), dist); // circular left distance
            }
            res.push_back(dist);
        }
        return res;
    }
};


int main (){

    
    return 0;
}