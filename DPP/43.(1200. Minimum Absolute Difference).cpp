#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());

        int n = arr.size();

        int minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        vector<vector<int>> returnvector;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                returnvector.push_back({arr[i], arr[i + 1]});
            }
        }

        return returnvector;
    }
};



int main (){

    
    return 0;
}