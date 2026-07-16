#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:

    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool DFS(int node,
             vector<bool> &visited,
             vector<bool> &recStack,
             stack<int> &st)
    {
        visited[node] = true;

        // Node currently in recursion
        recStack[node] = true;

        // Visit all neighbours
        for(int neighbour : adj[node])
        {
            if(!visited[neighbour])
            {
                if(DFS(neighbour, visited, recStack, st))
                    return true;
            }

            // Cycle detected
            else if(recStack[neighbour])
            {
                return true;
            }
        }

        // Remove from recursion stack
        recStack[node] = false;

        // Push into stack after processing
        st.push(node);

        return false;
    }

    void topologicalSort()
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        stack<int> st;

        // Visit every node
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(DFS(i, visited, recStack, st))
                {
                    cout<<"Cycle Detected!\n";
                    cout<<"No valid course order exists.\n";
                    return;
                }
            }
        }

        cout<<"\nValid Course Order:\n";

        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }

        cout<<endl;
    }
};

int main()
{
    int courses;

    cout<<"Enter number of courses : ";
    cin>>courses;

    Graph g(courses);

    int prerequisites;

    cout<<"Enter number of prerequisite relations : ";
    cin>>prerequisites;

    cout<<"\nEnter each relation (Course1 Course2)\n";
    cout<<"Meaning: Course1 must be completed before Course2\n\n";

    for(int i=0;i<prerequisites;i++)
    {
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v);
    }

    g.topologicalSort();

    return 0;
}