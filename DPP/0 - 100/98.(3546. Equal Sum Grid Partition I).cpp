#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // checking half sums 

        int len1=grid[0].size(),len2=grid.size();
        int sum1=0,sum2=0;

        for (int i=0;i<len2/2;i++){
            for (int j=0;j<len1/2;j++){
                sum1=sum1+grid[i][j];
                sum2=sum2+grid[len1-i-1][len2-j-1];
            }
        }

        if ((sum1+sum2)%2!=0){
            return false;
        }
        return true;
    }
};


int main (){

    
    return 0;
}