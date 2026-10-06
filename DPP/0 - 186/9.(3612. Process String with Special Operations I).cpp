#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    string processStr(string s) {
        string returnstr;

        for (int i=0;i<s.size();i++){
            /*
            A '*' removes the last character from result, if it exists.
            A '#' duplicates the current result and appends it to itself.
            A '%' reverses the current result.
            */

            if (s[i]=='*'){
                if (returnstr.size()>0){
                    returnstr.pop_back();
                }
            }
            else if (s[i]=='#'){
                returnstr+=returnstr;
            }
            else if (s[i]=='%'){
                reverse(returnstr.begin(),returnstr.end());
            }
            else{
                returnstr+=s[i];
            }
        }
        return returnstr;
    }
};


int main (){

    
    return 0;
}