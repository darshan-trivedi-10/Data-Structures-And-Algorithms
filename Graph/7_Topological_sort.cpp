// https://practice.geeksforgeeks.org/problems/topological-sort/1/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    void findTopoSort(vector<int> adj[], bool visited[], stack<int> &st, int node)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (visited[it] == false)
            {
                findTopoSort(adj, visited, st, it);
            }
        }

        st.push(node);
    }

public:
    vector<int> topoSort(int n, vector<int> adj[])
    {
        bool visited[n];
        memset(visited, false, sizeof visited);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                findTopoSort(adj, visited, s, i);
            }
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}