#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int maxlen=s.size();
        int currcount=1,prevcount=0,total_substrings=0;

        for (int i=1;i<maxlen;i++){
            if (s[i-1]==s[i])// if prev and curr character same , extend curr group
            {
                currcount++;
            }
            else {// char isnt same so we have to do 3 things 

                total_substrings+=min(currcount,prevcount);//the number of balanced substrings between two groups is the minimum of their sizes

                prevcount=currcount;//shift current group to previous

                currcount=1;//reset current for the new character
            }
        }

        total_substrings+=min(prevcount,currcount);// adding the last leftover groups

        return total_substrings;
    }
};


int main (){

    
    return 0;
}