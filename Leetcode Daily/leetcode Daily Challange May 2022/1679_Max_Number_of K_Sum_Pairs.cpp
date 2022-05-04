// https://leetcode.com/problems/max-number-of-k-sum-pairs/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int num1 = nums[i], num2 = k - nums[i];
            if (mpp.find(num2) != mpp.end() && mpp[num2] > 0)
            {
                ans++;
                mpp[num2]--;
            }
            else
            {
                mpp[num1]++;
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