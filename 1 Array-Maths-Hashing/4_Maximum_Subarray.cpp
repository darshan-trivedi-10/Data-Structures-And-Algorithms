// https://leetcode.com/problems/maximum-subarray/submissions/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cs = 0, ms = -1, max = INT_MIN;
        bool all_negetive = 1;
        for (auto element : nums)
        {
            if (element >= 0)
            {
                all_negetive = 0;
            }
            cs += element;
            if (cs > ms)
            {
                ms = cs;
            }
            if (cs < 0)
            {
                cs = 0;
            }

            if (max < element)
            {
                max = element;
            }
        }

        if (all_negetive)
        {
            return max;
        }

        return ms;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}