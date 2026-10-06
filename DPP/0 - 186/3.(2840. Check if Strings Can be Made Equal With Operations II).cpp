#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

/*

yesterday i hardcoded all the possiblilties as there strings have fixed length of 4 


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Since the strings here have a fixed length of 4 so hardcoded all the possibilities 
        return ((s1[0] == s2[0] && s1[2] == s2[2]) || 
                (s1[0] == s2[2] && s1[2] == s2[0])) &&
                
               ((s1[1] == s2[1] && s1[3] == s2[3]) ||
                (s1[1] == s2[3] && s1[3] == s2[1]));
    }
};

but today lengths aare equal but not fixed 
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even1[26]={}, odd1[26]={};
        int even2[26]={}, odd2[26]={};

        for (int i=0; i<s1.size(); i++){
            if (i%2==0){
                even1[s1[i]-'a']++;
                even2[s2[i]-'a']++;
            } else {
                odd1[s1[i]-'a']++;
                odd2[s2[i]-'a']++;
            }
        }

        // even positions must have same freq in both strings
        for (int i=0; i<26; i++){
            if (even1[i]!=even2[i]) {
                return false;
            }
            if (odd1[i]!=odd2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main (){

    
    return 0;
}