#include<iostream>
#include<queue>
#include<vector>

using namespace std ;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        // adjacency list ; adj[u] ={neighbor, cost}
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto e : edges) {
            int u = e[0];  // start node
            int v = e[1];  // end node
            int w = e[2];  // edge weight
            
            // direction: u -> v costs w
            adj[u].push_back({v, w});
            
            // reversed direction: v -> u costs 2*w (penalty for reversing)
            adj[v].push_back({u, 2*w});
        }
        
        //Dijkstra  setup
        const long long INF = 1e18;  // Large value for inf
        
        // dis[i] = minimum cost to reach node i from node 0
        vector<long long> dis(n, INF);
        
        // min-heap priority queue: {cost, node}
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<>> pq;
        
        //start from node 0 with cost 0
        dis[0] = 0;
        pq.push({0, 0});  // {cost, node}
        
        //Dijkstra's main loop
        while(!pq.empty()) {
            auto [cost, u] = pq.top();  // get node with minimum cost
            pq.pop();
            
            // skip if we have already found a better path to this node
            // this happens because we may add same node multiple times to pq
            if(cost > dis[u]) continue;
            
            // relax all edges from current node u
            for(auto &[v, w] : adj[u]) {  // for each neighbor v with edge weight w
                
                // if going through u to reach v is cheaper than current best
                if(cost + w < dis[v]) {
                    dis[v] = cost + w;  // update minimum cost to v
                    pq.push({dis[v], v});  // add to queue for further exploration
                }
            }
        }
        
        // check if destination (n-1) is reachable
        return dis[n-1] == INF ? -1 : dis[n-1];
    }
};



int main (){

    
    return 0;
}