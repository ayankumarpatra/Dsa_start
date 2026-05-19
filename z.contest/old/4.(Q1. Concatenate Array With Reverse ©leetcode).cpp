#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<regex>

using namespace std ;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> rev=nums;

        reverse(rev.begin(),rev.end());

        nums.insert(nums.end(),rev.begin(),rev.end());

        return nums;
    }
};


/// Q2. Count Valid Word Occurrences

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for (const string& chunk : chunks) {
            s += chunk;
        }

        unordered_map<string, int> wordcount;
        int n = s.length();
        string currword = "";

        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                currword += s[i];
            } 
            else if (s[i] == '-' && i > 0 && i < n - 1 && islower(s[i-1]) && islower(s[i+1])) {
                currword += s[i];
            } 
            else {
                if (!currword.empty()) {
                    wordcount[currword]++;
                    currword = "";
                }
            }
        }
        
        if (!currword.empty()) {
            wordcount[currword]++;
        }
        vector<int> returnvect;
        for (const string& q : queries) {
            returnvect.push_back(wordcount[q]);
        }

        return returnvect;
    }
};



int main (){

    
    return 0;
}