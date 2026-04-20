#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        sort(s.begin(),s.end());
        string resultstr="";

        for (int i=0;i<s.size();i++){
            resultstr+=s[i];
            char currchar=s[i];
            while (i<s.size() && s[i]==currchar )
            {
                i++;
            }
            
        }
        return resultstr;
    }
};


int main (){

    
    return 0;
}