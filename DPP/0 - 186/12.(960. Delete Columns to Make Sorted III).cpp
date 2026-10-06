#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int rowlen=strs.size();
        int collen=strs[0].size();

        vector<int> KeepCol (collen,1);

        int MaxKeep=1;

        for (int j=0;j<collen;j++){
            for (int i=0;i<j;i++){

                bool compitable=true;

                for (int k=0;k<rowlen;k++){
                    if(strs[k][i]>strs[k][j]){
                        compitable=false;
                        break;
                    }
                }

                if (compitable){
                    KeepCol[j]=max(KeepCol[j],KeepCol[i]+1);
                }
            }
            MaxKeep=max(MaxKeep,KeepCol[j]);
        }
        return collen-MaxKeep;
    }
};


int main (){

    
    return 0;
}