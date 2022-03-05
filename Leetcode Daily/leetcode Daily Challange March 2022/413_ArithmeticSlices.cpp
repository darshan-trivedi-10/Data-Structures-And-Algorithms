// https://leetcode.com/problems/arithmetic-slices/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        if (n < 3)
        {
            return ans;
        }

        for (int i = 0; i < (n - 2); i++)
        {
            int diff = nums[i] - nums[i + 1];
            for (int j = i + 2; j < n; j++)
            {
                int currDiff = nums[j - 1] - nums[j];
                if (currDiff == diff)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}