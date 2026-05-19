
#include<iostream>
#include<string>
#include<vector>

using namespace std ;

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i=0;i<s.size()-1;i++){
            if (abs(int(s[i])-int(s[i+1]))>2){
                return false;
            }
        }
        return true;
    }
};


int main (){

    
    return 0;
}