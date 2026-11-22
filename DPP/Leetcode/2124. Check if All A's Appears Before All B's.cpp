#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    bool checkString(string s) {
        
        int first_b = -1; // index of first b occurence ;

        for (int i=0 ; i< s.length() ; i++){
            if (s[i] == 'b'){
                first_b = i ;
                break;
            }
        }

        // check if any a occuring after that 

        int i = first_b;

        for (i; i<s.length() ; i++ ){
            if (s[i] == 'a'){
                return false;
            }
        }

        return true;
    }
};


int main (){

    
    return 0;
}