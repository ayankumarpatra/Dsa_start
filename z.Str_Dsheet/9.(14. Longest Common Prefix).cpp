#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==1){
            return strs[0];
        }
        string return_str="";

        for (int i=0;i<strs[0].size();i++){
            bool add=false;
            for (int j=0;j<strs.size()-1;j++){
                if (strs[j][i]==strs[j+1][i]){
                    add=true;
                }
                else {
                    add=false;
                    return return_str;
                }
            }

            if (add){
                return_str=return_str+strs[0][i];
            }
        }
        return return_str;
    }
};



int main (){

    
    return 0;
}