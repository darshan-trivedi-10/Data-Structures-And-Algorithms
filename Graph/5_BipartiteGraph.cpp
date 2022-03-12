// https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

// Using BFS
class Solution
{
public:
    bool checkForBipartite(vector<vector<int>> &adj, int visited[], int node)
    {
        visited[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();
            for (auto it : adj[currNode])
            {
                if (visited[it] == -1)
                {
                    visited[it] = 1 - visited[currNode];
                    q.push(it);
                }
                else if (visited[it] == visited[currNode])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &adj)
    {
        int n = adj.size();
        int visited[n];
        memset(visited, -1, sizeof visited);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == -1)
            {
                if (!checkForBipartite(adj, visited, i))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

// Using DFS
class Solution
{

    bool checkForBipartite(vector<vector<int>> &adj, int visited[], int node)
    {
        for (auto it : adj[node])
        {
            if (visited[it] == -1)
            {
                visited[it] = 1 - visited[node];
                if (checkForBipartite(adj, visited, it) == false)
                {
                    return false;
                }
            }
            else if (visited[it] == visited[node])
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &adj)
    {
        int n = adj.size();
        int visited[n];
        memset(visited, -1, sizeof visited);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == -1)
            {
                visited[i] = 1;
                if (!checkForBipartite(adj, visited, i))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}