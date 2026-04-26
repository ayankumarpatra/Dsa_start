#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool validDigit(int n, int x) {
        string val=to_string(n);
        char checkval=char(x + '0');
        if (val[0]==checkval){
            return false;
        }

        else {
            for (int i=1;i<val.size();i++){
            if (val[i]==checkval){
            return true;
            }
            }
        }

        return false;
    }
};


int main (){

    
    return 0;
}