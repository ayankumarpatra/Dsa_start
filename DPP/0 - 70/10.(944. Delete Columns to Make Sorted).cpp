#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minDeletionSize(vector<string>& strs){
        int del=0;
        int rowlen=strs.size();
        int collen=strs[0].size();// col len is equal as all strings are of same length 

        for (int j=0;j<collen;j++){
            // first check if this col is sorted or not , will check by ascii value 
            for(int i=0;i<rowlen-1;i++){
                if(strs[i][j]>strs[i+1][j]){// if bellow char is greater than the upper one 
                    del++;
                    break;// no need to check more , go to next ;
                }
            }
        }
        return del;
    }
};



int main (){

    
    return 0;
}