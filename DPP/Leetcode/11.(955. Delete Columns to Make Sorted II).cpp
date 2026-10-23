#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
    int Collen=strs[0].size();// as all strings are of same length given 
    int Rowlen=strs.size();// no of rows=
    
    int del=0;

    vector<bool> issorted(Rowlen-1,false);

    for (int j=0;j<Collen;++j){
        bool ToDel=false;

        // first check if this col is valid
        for (int i=0;i<Rowlen-1;++i){
            if(!issorted[i] && strs[i][j]>strs[i+1][j]){
                ToDel=true;
                break;
            }
        }

        if (ToDel){
            del++;
        }

        else {
            for (int i=0;i<Rowlen-1;++i){
                if (strs[i][j]<strs[i+1][j]){
                    issorted[i]=true;
                }
            }
        }
    }
    return del;
    }
};


int main (){

    
    return 0;
}