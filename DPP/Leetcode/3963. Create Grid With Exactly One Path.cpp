#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

//  300 is the 24th triangular number. 

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector <string> returnvect ;

        string first , remaining ;

        for (int i=0 ;i<n-1 ; i++){
            first += '.';
            remaining += '#';
        }
        
        first += '.';
        returnvect.push_back(first);
        
        remaining += '.';
        for (int i=1; i<m ; i++){
            returnvect.push_back(remaining);
        }

        return returnvect;
    }
};


int main (){

    
    return 0;
}