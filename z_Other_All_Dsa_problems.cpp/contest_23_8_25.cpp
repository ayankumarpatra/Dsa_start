#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<bitset>
#include<string>

using namespace std ;


bool isPalindromic(string s) {
        string binaryStr = "";
    
    for (char c : s) {
        binaryStr +=bitset<8>(c).to_string();
    }
    
    int left = 0;
    int right = binaryStr.length() - 1;
    
    while (left < right) {
        if (binaryStr[left] != binaryStr[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;

    }



#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> returnvect;
    long long curr = lower;
    
    for (int num : nums) {
        if (num < curr) {
            continue;
        }
        
        if (num > upper) {
            break;
        }
        
        if (num > curr) {
            returnvect.push_back({(int)curr, num - 1});
        }
        
        curr = (long long)num + 1;
    }
    
    if (curr <= upper) {
        returnvect.push_back({(int)curr, upper});
    }
    
    return returnvect;
}


int main (){

    
    return 0;
}