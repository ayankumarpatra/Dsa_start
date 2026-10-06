#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // x startrow , y startcol, z size 

        for (int  i=0;i<k/2;i++){/*
            you may think why k/2 , becuase we only need to travarse half time .. like think we swapped a with last z 
            now when we reach z , we will again swap it with a , so finally matrix become same , no chnage 
            */
            for (int j=0;j<k;j++){
                int toprow=x+i;// x start + i to move
                int bottomrow=x+k-i-1;// x start , k matrix size , -i to move backwards and -1 as array are 0 indexed 

                int currcol=y+j;// y startcol , j col iterator 

                swap (grid[toprow][currcol],grid[bottomrow][currcol]);
            }
        }

        return grid;
    }
};


int main (){

    
    return 0;
}