#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:

    void fillrows( vector<vector<int>>& mainvect,const vector<int>& prevvect, int currlen){
        vector<int> tempvect(currlen,1);
        int temp_point=1;

        for (int i=0;i<prevvect.size()-1;i++){
            tempvect[temp_point]=prevvect[i]+prevvect[i+1];

            temp_point++;
        }

        mainvect.push_back(tempvect);
    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> returnvect;
        vector<int> tempvect;
        // hardcoding for 1 , 2 rows

        if (numRows<1){
            returnvect.push_back(tempvect);
            return returnvect;
        }
        tempvect.push_back(1);
        returnvect.push_back(tempvect);
        
        if (numRows==1){
            return returnvect;
        }
        
        tempvect.push_back(1);
        returnvect.push_back(tempvect);
        
        if (numRows==2){
            return returnvect;
        }

        tempvect.clear();

        for (int i=3;i<=numRows;i++){
            fillrows(returnvect,returnvect[returnvect.size()-1],i);
        }

        return returnvect;
    }
};


int main (){

    
    return 0;
}