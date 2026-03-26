#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class solution {
public:
    bool canpartitiongrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;

        // calculate total sum of the grid
        for(auto &row : grid) {
            for(auto &val : row) {
                total += val;
            }
        }

        // horizontal cuts
        long long prefix = 0;
        unordered_map<int, int> bottomfreq;

        // initialize bottom frequency map with all elements
        for(auto &row : grid) {
            for(auto &val : row) {
                bottomfreq[val]++;
            }
        }

        unordered_map<int, int> topfreq;
        for(int i = 0; i < m - 1; i++) {
            // move the entire row from bottom to top side
            for(int j = 0; j < n; j++) {
                int val = grid[i][j];
                prefix += val;
                topfreq[val]++;
                bottomfreq[val]--;
                if(bottomfreq[val] == 0) bottomfreq.erase(val);
            }

            long long bottom = total - prefix;
            if(prefix == bottom) return true;

            // check if moving one element can balance the difference
            long long diff = abs(prefix - bottom);
            if(prefix > bottom) {
                if(topfreq.count(diff)) return true;
            } else {
                if(bottomfreq.count(diff)) return true;
            }
        }

        // vertical cuts
        prefix = 0;
        unordered_map<int, int> rightfreq;
        for(auto &row : grid) {
            for(auto &val : row) {
                rightfreq[val]++;
            }
        }

        unordered_map<int, int> leftfreq;
        for(int j = 0; j < n - 1; j++) {
            // move the entire column from right to left side
            for(int i = 0; i < m; i++) {
                int val = grid[i][j];
                prefix += val;
                leftfreq[val]++;
                rightfreq[val]--;
                if(rightfreq[val] == 0) rightfreq.erase(val);
            }

            long long right = total - prefix;
            if(prefix == right) return true;

            // check if moving one element can balance the difference
            long long diff = abs(prefix - right);
            if(prefix > right) {
                if(leftfreq.count(diff)) return true;
            } else {
                if(rightfreq.count(diff)) return true;
            }
        }

        return false;
    }
};


int main (){

    
    return 0;
}