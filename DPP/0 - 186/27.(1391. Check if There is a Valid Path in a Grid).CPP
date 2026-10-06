#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

/*

3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.
*/
class Solution {
public:
    // Directions for each pipe type 1-6
    vector<vector<pair<int, int>>> directions = {
        {}, // dummy for index 0
        {{0, -1}, {0, 1}},  // 1: left, right
        {{-1, 0}, {1, 0}},  // 2: up, down
        {{0, -1}, {1, 0}},  // 3: left, down
        {{0, 1}, {1, 0}},   // 4: right, down
        {{0, -1}, {-1, 0}}, // 5: left, up
        {{0, 1}, {-1, 0}}   // 6: right, up
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            int type = grid[r][c];
            for (auto& dir : directions[type]) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // 1. Boundary check
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    // 2. Connectivity check: Does next pipe connect back to (r, c)?
                    int nextType = grid[nr][nc];
                    for (auto& backDir : directions[nextType]) {
                        if (nr + backDir.first == r && nc + backDir.second == c) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main (){

    
    return 0;
}