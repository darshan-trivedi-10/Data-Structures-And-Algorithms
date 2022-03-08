#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

void AdjacencyMatrixRepresentation()
{
    // Space Complexity : O((N+1)* (N+1))
    int n, m;
    cin >> n >> m;
    // declare the adjacent matrix
    int arr[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        // take edges as input
        int u, v;
        cin >> u >> v;

        arr[u][v] = arr[v][u] = 1;
    }
}

void AdjacencyListRepresentation()
{
    // Space Complexity : O(N * (2 * M)) in Undirected Graph
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    vector<int> arr[n];

    for (int i = 0; i < m; i++)
    {
        // take edges as input
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
}

// Weight Graph
void AdjacencyListRepresentation()
{
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    vector<pair<int, int>> arr[n];

    for (int i = 0; i < m; i++)
    {
        // take edges as input
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({v, w});
        arr[v].push_back({u, w});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    


    return 0;
}