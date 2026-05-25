#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>

using namespace std ;

class Solution {
public:
    int Numrev(int x) {// func to reverse the number
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastSeen; //maps reversed value with last index stored
        int minDist = INT_MAX;

        for (int j = 0; j < (int)nums.size(); j++) {
            int rev = Numrev(nums[j]);

            // check if current number was stored as a reverse of some earlier number
            if (lastSeen.count(nums[j])) {
                minDist = min(minDist, j - lastSeen[nums[j]]);
            }

            //store the reversed value
            lastSeen[rev] = j;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }

};


int main (){

    
    return 0;
}