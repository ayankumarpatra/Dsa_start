#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int maximumLengthSubstring(string s) {

        int n= s.size();
        
        unordered_map<char,int> freq;// key , freq pair

        int left=0,maxlen=0;

        for (int right=0; right<n ; right++){

            freq[ s[right] ]++;

            while ( freq[s[right]]>2){
                freq[s[left]]--;
                left++;
            }

            maxlen= max ( maxlen, right-left+1);
        }

        return maxlen;
    }
};


int main (){

    
    return 0;
}