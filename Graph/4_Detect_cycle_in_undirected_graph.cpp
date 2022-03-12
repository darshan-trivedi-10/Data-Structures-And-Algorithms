// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/

#include <bits/stdc++.h>
using namespace std;

// Using DFS
class Solution
{
    bool checkCycle(vector<int> adj[], bool visited[], int node, int parent)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (visited[it] == false)
            {
                if (checkCycle(adj, visited, it, node))
                {
                    return true;
                }
            }
            else if (it != parent)
            {
                return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int n, vector<int> adj[])
    {
        bool visited[n + 1];
        memset(visited, false, sizeof visited);
        int parent = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                if (checkCycle(adj, visited, i, parent))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

// Using BFS
class SolutionBFS
{
    bool checkCycle(vector<int> adj[], bool visited[], int node)
    {
        visited[node] = true;
        queue<pair<int, int>> q;
        q.push({node, -1});
        while (!q.empty())
        {
            int currNode = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[currNode])
            {
                if (visited[it] == false)
                {
                    q.push({it, currNode});
                    visited[it] = true;
                }
                else if (parent != it)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int n, vector<int> adj[])
    {
        bool visited[n + 1];
        memset(visited, false, sizeof visited);
        int parent = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                if (checkCycle(adj, visited, i))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}