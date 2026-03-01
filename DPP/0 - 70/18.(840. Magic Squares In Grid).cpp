#include<iostream>
#include<vector>

using namespace std ;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int count=0;

        for (int i=0;i<=rows-3;i++){
            for (int j=0;j<=cols-3;j++){

                // center must be 5 

                if (grid[i+1][j+1]!=5){
                    continue;// skip the remaining iteration 
                }

                // verfiy all num 1-9 appear only once 

                vector<bool> seen(10,false);

                bool valid=true;

                for (int temprow=i;temprow<i+3;temprow++){
                    for (int tempcol=j;tempcol<j+3;tempcol++){
                        int tempval=grid[temprow][tempcol];

                        if (tempval<1 || tempval>9 || seen[tempval]){
                            valid=false;
                            break;
                        }

                        seen[tempval]=true;
                    }
                }

                if (!valid){
                    continue;
                }

                // check row , col etcs ums 

                int s1=grid[i][j] + grid[i][j+1] +grid[i][j+2];
                int s2=grid[i+1][j] + grid[i+1][j+1] +grid[i+1][j+2];
                int s3=grid[i+2][j] + grid[i+2][j+1] +grid[i+2][j+2];

                if (s1!=15 || s2!=15|| s3!=15){
                    continue;
                }

                int c1=grid[i][j] + grid[i+1][j] + grid [i+2][j];
                int c2=grid[i][j+1] + grid[i+1][j+1] + grid [i+2][j+1];
                int c3=grid[i][j+2] + grid[i+1][j+2] + grid [i+2][j+2];

                if (c1!=15 || c2!=15 || c3!=15){
                    continue;
                }

                // checling diagonals

                int d1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                int d2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

                if (d1!=15 || d2!=15){
                    continue;
                }
                count++;
            }
        }

        return count;
    }
};


int main (){

    
    return 0;
}