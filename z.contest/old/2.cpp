#include<iostream>
#include<stack>
#include<vector>
#include<climits>

using namespace std ;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddmin= INT_MAX,evenmin = INT_MAX;
        int oddcount = 0, evencount = 0;

        for (int x : nums1) {
            if (x % 2 == 0) {
                evencount++;
                evenmin = min(evenmin, x);
            } else {
                oddcount++;
                oddmin = min(oddmin, x);
            }
        }

        bool all_evenspresent = (oddcount == 0);
        bool all_oods_present = (evencount == 0) || (oddmin < evenmin);

        return all_evenspresent || all_oods_present;
    }
};


int main (){

    
    return 0;
}