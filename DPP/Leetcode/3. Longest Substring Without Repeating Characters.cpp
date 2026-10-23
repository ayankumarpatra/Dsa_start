#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std ;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int last_removed=0;

        unordered_set<char> us;

        int currlen=0,maxlen=0,curr_elements;

        for (int i=0;i<s.size();i++){
            curr_elements=us.size();
            if (us.contains(s[i])){
                while (us.contains(s[i]) && us.size()!=0)
                {
                    us.erase(s[last_removed++]);
                }
            }
            
            us.insert(s[i]);

            maxlen = max (maxlen,int(us.size()));
        }

        return maxlen;
        
    }
};



int main (){

    
    return 0;
}