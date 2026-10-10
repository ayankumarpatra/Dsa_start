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

        unordered_set<int> us;

        int currlen=0,maxlen=0,curr_elements;

        for (int i=0;i<s.size();i++){
            curr_elements=us.size();
            us.insert(s[i]);
            if (us.size()==curr_elements){
                while (us.size() == curr_elements && us.size()!=0)
                {
                    
                }
                
            }
        }
        
    }
};



int main (){

    
    return 0;
}