// https://leetcode.com/problems/shift-2d-grid/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int newJ = (j + k) % m; // (j + numbers of columns added)%m

                int newI = (i + (j + k) / m) % n; // (i + numbers of rows added)%n

                ans[newI][newJ] = grid[i][j];
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}