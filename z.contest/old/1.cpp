#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddcount = 0;
        for (int x : nums1)
            if (x % 2 != 0) oddcount++;

        bool odd_all  = (oddcount >= 1);
        bool even_all = (oddcount == 0 || oddcount >= 2);

        return odd_all || even_all;
    }
};


int main (){

    
    return 0;
}