#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        string newstr = s + s;

        for (int i = 1; i < s.size(); i++) {

            int olds = 0;
            int j = i;

            while (olds < s.size() && newstr[j] == s[olds]) {
                olds++;
                j++;
            }

            if (olds == s.size())
                return true;
        }

        return false;
    }
};


int main (){

    
    return 0;
}