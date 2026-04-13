#include<iostream>
#include<algorithm>
#include<string>

using namespace std ;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }

        string str=to_string(x);

        int maxlen=str.size()/2;

        for (int i=0;i<maxlen;i++){
            if(str[str.size()-i-1]!=str[i]){
                return false;
            }
        }

        return true;
    }
};


int main (){

    
    return 0;
}