#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

/*
Input :
6 5
1 2
2 3
3 5
1 5
4 6

Output :
1 2 5 3 4 6
*/

void bfs(vector<int> arr[], bool visited[], vector<int> &ans, int index)
{
    queue<int> q;
    q.push(index);
    visited[index] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : arr[node])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    bool visited[n + 1];
    memset(visited, false, sizeof visited);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            bfs(arr, visited, ans, i);
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}