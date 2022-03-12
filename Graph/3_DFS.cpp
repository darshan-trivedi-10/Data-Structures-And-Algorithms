#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

void dfs(vector<int> arr[], vector<int> &ans, bool visited[], int index)
{
    visited[index] = true;
    ans.push_back(index);
    for (auto it : arr[index])
    {
        if (!visited[it])
        {
            dfs(arr, ans, visited, it);
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

    vector<int> ans;
    bool visited[n + 1];
    memset(visited, false, sizeof visited);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(arr, ans, visited, i);
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}