#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int total =0;

        for (int currnum : s){
            total+=currnum;
        }

        sort (g.begin(),g.end());

        for (int i=0; i<g.size() ;i++){
            
        }
    }
};


int main (){

    
    return 0;
}