// https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// Time Complexity : O(log(n*m)), Space Complexity : O(1).
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int s = 0, e = (n * m) - 1;
        bool present = false;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            int curr_e = matrix[mid / m][mid % m];
            if (curr_e == target)
            {
                present = true;
                break;
            }
            else if (curr_e > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return present;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}