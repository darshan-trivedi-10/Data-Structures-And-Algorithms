// https://leetcode.com/problems/cherry-pickup/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findMaxCherry(vector<vector<int>> &arr, int i, int j)
    {
        int n = arr.size();
        if (i == n - 1 && j == n - 1)
        {
            return arr[i][j];
        }

        if (i < 0 || j < 0 || i >= n && j >= n || arr[i][j] == -1)
        {
            return INT_MIN;
        }

        return arr[i][j] + max({findMaxCherry(arr, i + 1, j), findMaxCherry(arr, i, j + 1), findMaxCherry(arr, i + 1, j + 1), findMaxCherry(arr, i - 1, j), findMaxCherry(arr, i, j - 1), findMaxCherry(arr, i - 1, j - 2)});
    }

public:
    int cherryPickup(vector<vector<int>> &arr)
    {
        int n = arr.size();
        return findMaxCherry(arr, 0, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}