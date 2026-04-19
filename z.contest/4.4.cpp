#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

class Solution {
public:
    vector<int> path_idx;
    
    void pathbmaker(const string& directions) {
        int r = 0, c = 0;
        path_idx.push_back(r * 4 + c);
        for (char ch : directions) {
            if (ch == 'D') r++;
            else c++;
            path_idx.push_back(r * 4 + c);
        }
    }
    string num;
    long long memo[16][8][10][2];
    bool visited[16][8][10][2];
    
    long long dp(int pos, int pathst, int lastdg, bool tight) {
        if (pos==16) {
            return (pathst==7) ? 1 : 0;
        }
        
        int t= tight ? 1 : 0;
        if (visited[pos][pathst][lastdg][t])
            return memo[pos][pathst][lastdg][t];
        
        visited[pos][pathst][lastdg][t] = true;
        
        int limit = tight ? (num[pos] - '0') : 9;
        long long res = 0;
        
        bool ispathcell = (pathst < 7 && path_idx[pathst] == pos);
        
        for (int d = 0; d <= limit; d++) {
            bool newtigh = tight && (d == limit);
            
            if (ispathcell) {
                if (d >= lastdg) {
                    res += dp(pos + 1, pathst + 1, d, newtigh);
                }

            } else {
                res += dp(pos + 1, pathst, lastdg, newtigh);
            }
        }
        
        return memo[pos][pathst][lastdg][t] = res;
    }
    
    long long countupto(long long x, const string& directions) {
        if (x <= 0) return 0;

        num = to_string(x);
        while (num.size() < 16) num = "0" + num;
        
        memset(visited, false, sizeof(visited));
        return dp(0, 0, 0, true);
    }
    
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        pathbmaker(directions);
        return countupto(r, directions) - countupto(l - 1, directions);
    }
};







class Solution {
public:
    vector<int> path_idx;
    
    void pathbmaker(const string& directions) {
        int r = 0, c = 0;
        path_idx.push_back(r * 4 + c);
        for (char ch : directions) {
            if (ch == 'D') r++;
            else c++;
            path_idx.push_back(r * 4 + c);
        }
    }

    string num;
    long long memo[16][8][11][2];
    bool visited[16][8][11][2];
    
    long long dp(int pos, int pathst, int lastdg, bool tight) {
        if (pos == 16) {
            return (pathst == 7) ? 1 : 0;
        }
        
        int t = tight ? 1 : 0;
        if (visited[pos][pathst][lastdg][t])
            return memo[pos][pathst][lastdg][t];
        visited[pos][pathst][lastdg][t] = true;
        
        int limit = tight ? (num[pos] - '0') : 9;
        long long res = 0;
        
        bool ispathcell = (pathst < 7 && path_idx[pathst] == pos);
        
        for (int d = 0; d <= limit; d++) {
            bool newtigh = tight && (d == limit);
            
            if (ispathcell) {
                if (lastdg == 10 || d >= lastdg) {
                    res += dp(pos + 1, pathst + 1, d, newtigh);
                }
            } else {
                res += dp(pos + 1, pathst, lastdg, newtigh);
            }
        }
        
        return memo[pos][pathst][lastdg][t] = res;
    }
    
    long long countupto(long long x) {
        if (x <= 0) return 0;
        num = to_string(x);
        while (num.size() < 16) num = "0" + num;
        memset(visited, false, sizeof(visited));
        return dp(0, 0, 10, true)-1;
    }
    
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        pathbmaker(directions);
        return countupto(r) - countupto(l - 1);
    }
};


int main (){

    
    return 0;
}