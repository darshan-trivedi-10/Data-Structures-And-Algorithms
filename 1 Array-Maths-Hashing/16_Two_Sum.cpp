// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            if (mpp.find(target - nums[i]) != mpp.end())
            {
                ans.push_back(mpp[target - nums[i]]);
                ans.push_back(i);
                break;
            }

            mpp[nums[i]] = i;
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