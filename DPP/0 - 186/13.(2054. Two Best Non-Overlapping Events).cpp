#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        if (n == 0) return 0;

        sort(events.begin(), events.end());

        vector<int> suffixmax(n);
        suffixmax[n-1] = events[n-1][2];

        for (int i = n - 2; i >= 0; i--) {
            suffixmax[i] = max(events[i][2], suffixmax[i + 1]);
        }

        int maxVal = 0;

        for (int i = 0; i < n; i++) {

            // take current event only
            maxVal = max(maxVal, events[i][2]);

            int endtime = events[i][1];

            int left = i + 1, right = n - 1;
            int nextindex = -1;

            // proper binary search
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > endtime) {
                    nextindex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nextindex != -1) {
                maxVal = max(maxVal, events[i][2] + suffixmax[nextindex]);
            }
        }

        return maxVal;
    }
};



int main (){

    
    return 0;
}