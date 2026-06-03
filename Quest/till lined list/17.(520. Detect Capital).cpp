#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    bool detectCapitalUse(string word) {
        /*
        allowed
        All letters in this word are capitals, like "USA".
        All letters in this word are not capitals, like "leetcode".
        Only the first letter in this word is capital, like "Google"
        */
       
       if (word.size()==1){
           return true;
       }

       else if (word.size()==2){
        if ((isupper(word[0]) && islower(word[1])) || (islower(word[0]) && isupper(word[1]))){
                return false;
            }
       }


        for (int i=1;i<word.size()-1;i++){
            if ((isupper(word[i]) && islower(word[i+1])) || (islower(word[i]) && isupper(word[i+1]))){
                return false;
            }
        }

        return true;
    }
};


int main (){

    
    return 0;
}