#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

/*

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string returnstr="";

        for (int i=s.size()-1;i>=0;i){
            int j=k;

            while (j>0 && i>=0)
            {
                if (i>=0 && s[i]!='-'){
                    returnstr= char(toupper(s[i])) +returnstr;
                    j--;
                }
                i--;
            }
            if (i>=0){
                returnstr='-'+returnstr;   
            }
        }

        if (!returnstr.empty() && returnstr.front()=='-'){
            returnstr.erase(0,1);
        }

        return returnstr;
    }
};

*/

// got tle so approach 2 :)

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        // building from forward ;

        string returnstr="";

        for (int i=s.size()-1;i>=0;i){
            int count=0;

            while (i>=0 && count<k)
            {
                if (s[i]!='-'){
                    returnstr+=s[i];
                    count++;
                }
                i++;
            }
            returnstr+='-';
        }

        reverse(returnstr.begin(),returnstr.end());

        return returnstr;
    }
};

int main (){

    
    return 0;
}