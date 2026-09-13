#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std ;


class Solution {
public:
    void setzero(vector<vector<int>>& matrix , int row , int col ){
        for (int currow=0;currow<matrix.size();currow++){
            matrix[currow][col]=0;
        }

        for (int currcol=0; currcol<matrix[0].size() ; currcol++){
            matrix[row][currcol]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {


        vector<pair<int,int>> zeroidx;

        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    zeroidx.push_back({i,j});
                }
            }
        }

        for (auto currpair:zeroidx){
            setzero(matrix,currpair.first,currpair.second);
        }
    }
};


// optimized version

class Solution {
public:

    void setzerorow (vector<vector<int>>& matrix , int row ){
        for (int currcol=0; currcol<matrix[0].size() ; currcol++){
            matrix[row][currcol]=0;
        }
    }
    
    void setzerocol (vector<vector<int>>& matrix , int col ){
        for (int currow=0;currow<matrix.size();currow++){
            matrix[currow][col]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        unordered_set<int> zerorow;
        unordered_set<int> zerocol;
        
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    zerorow.emplace(i);
                    zerocol.emplace(j);
                }
            }
        }

        for (int currrow:zerorow ){
            setzerorow(matrix,currrow);
        }
        for (int currcol:zerocol ){
            setzerocol(matrix,currcol);
        }
    }
};

int main (){

    
    return 0;
}