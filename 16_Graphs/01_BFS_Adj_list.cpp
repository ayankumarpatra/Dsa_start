#include <bits/stdc++.h>
using namespace std;

const int N = 6;  // total nodes (0 to N-1)

vector<vector<int>> adj = {
    {1, 2},    // node 0 connects to 1, 2
    {0, 3, 4}, // node 1 connects to 0, 3, 4
    {0, 5},    // node 2 connects to 0, 5
    {1},       // node 3 connects to 1
    {1},       // node 4 connects to 1
    {2}        // node 5 connects to 2
};
// ────────────────────────────────────────────────────────

void bfs(int start) {
    vector<bool> visited(N, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int nb : adj[node])
            if (!visited[nb]) {
                visited[nb] = true;
                q.push(nb);
            }
    }
}

int main() {
    cout << "BFS (adj list): ";
    bfs(0);
}