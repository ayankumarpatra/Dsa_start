#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> temp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        if(grid[0][0]!=2) temp[0][0][grid[0][0]]=(grid[0][0]);
        else temp[0][0][grid[0][0]-1]=(grid[0][0]);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i!=0) {
                    for(int t=0;t<=k;t++) {
                        int d=(grid[i][j]==2 ? 1 : grid[i][j]);
                        if(t-d>=0 && temp[i-1][j][t-d]!=-1)temp[i][j][t]=max({temp[i][j][t],temp[i-1][j][t-d]+grid[i][j]});
                    }
                }
                if(j!=0) {
                    for(int t=0;t<=k;t++) {
                        int d=(grid[i][j]==2 ? 1 : grid[i][j]);
                        if(t-d>=0 && temp[i][j-1][t-d]!=-1)temp[i][j][t]=max({temp[i][j][t],temp[i][j-1][t-d]+grid[i][j]});
                    }
                }
            }
        }
        int ans=-1;
        for(int t=0;t<=k;t++) {
            ans=max(ans,temp[n-1][m-1][t]);
        }
        return ans;
    }
};


int main (){

    
    return 0;
}