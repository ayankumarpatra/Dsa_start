#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        queue<tuple<int,int,int>> q;
        
        for (auto& src:sources) {
            int r=src[0], c=src[1], color= src[2];
            if (dist[r][c] == 0) {
            grid[r][c]= max(grid[r][c],color);
            } else {
                dist[r][c]= 0;
                grid[r][c]= color;
                q.push({r,c,color});
            }
        
        }
        
        queue<tuple<int,int,int>> bfsq;
        fill(dist.begin(),dist.end(),vector<int>(m, INT_MAX));
        fill(grid.begin(),grid.end(),vector<int>(m, 0));
        
        for (auto& src : sources) {
            int r =src[0], c=src[1], color= src[2];
            grid[r][c]= max(grid[r][c], color);
            dist[r][c]=0;
        }
        for (auto& src: sources) {
            int r = src[0], c= src[1];
            bfsq.push({r,c, grid[r][c]});
        }
        
        int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!bfsq.empty()) {
            auto [r, c, color] = bfsq.front();
            bfsq.pop();
            
            if (grid[r][c] != color && dist[r][c] < INT_MAX) {
            }
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {continue;}
                
                int newdist = dist[r][c] + 1;
                
                if (newdist < dist[nr][nc]) {
                    dist[nr][nc] = newdist;
                    grid[nr][nc] = color;
                    bfsq.push({nr, nc, color});
                } else if (newdist == dist[nr][nc]) {
                    if (color > grid[nr][nc]) {
                        grid[nr][nc] = color;
                        bfsq.push({nr, nc, color});
                    }
                }
            }
        }
        
        return grid;
    }
};


int main (){

    
    return 0;
}