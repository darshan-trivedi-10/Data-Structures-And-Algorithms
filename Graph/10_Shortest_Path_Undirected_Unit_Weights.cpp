#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

void BFS(vector<int> adj[], int N, int src)
{
    int dist[N];
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < N; i++)
        cout << dist[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}