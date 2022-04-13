// https://leetcode.com/problems/spiral-matrix-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'



class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int i1 = 0, i2 = n - 1;
        int j1 = 0, j2 = n - 1;
        int num = 0;

        // result matrix
        vector<vector<int>> arr(n, vector<int>(n));
        while (i1 <= i2 && j1 <= j2)
        {
            // left to right (row will be fixed)
            for (int i = j1; i <= j2; ++i)
            {
                arr[i1][i] = ++num;
            }
            // move down(col will be fixed)
            for (int i = i1 + 1; i <= i2; ++i)
            {
                arr[i][j2] = ++num;
            }
            // move right to left
            // move  up
            if (i1 < i2 && j1 < j2)
            {
                // move right to left (row will be fixed)
                for (int i = j2 - 1; i > j1; --i)
                {
                    arr[i2][i] = ++num;
                }
                // move up (col will be fixed)
                for (int i = i2; i > i1; --i)
                {
                    arr[i][j1] = ++num;
                }
            }
            ++i1;
            --i2;
            ++j1;
            --j2;
        }
        return arr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}