#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std ;

class Solution {
public:
    int maxDepth(string s) {
        int braces=0;

        int maxcount=INT_MIN;

        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                braces++;
            }
            else if (s[i]==')'){ 
                braces--;
            }

            maxcount= max(maxcount,braces);
        }

        return maxcount;
    }
};


int main (){

    
    return 0;
}