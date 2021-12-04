// https://leetcode.com/problems/set-matrix-zeroes/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        bool col1 = 1;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                col1 = 0;
            }

            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }

            if (col1 == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// Solution - 2
class Solution
{
public:
    void findzero(vector<vector<int>> &matrix, vector<pair<int, int>> &setz)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    setz.push_back({i, j});
                }
            }
        }
    }
    void setZero(vector<vector<int>> &matrix, int i, int j)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int k = 0; k < n; k++)
        {
            matrix[k][j] = 0;
        }
        for (int k = 0; k < m; k++)
        {
            matrix[i][k] = 0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> setz;
        findzero(matrix, setz);

        for (int i = 0; i < setz.size(); i++)
        {
            int f = setz[i].first, s = setz[i].second;
            setZero(matrix, f, s);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
