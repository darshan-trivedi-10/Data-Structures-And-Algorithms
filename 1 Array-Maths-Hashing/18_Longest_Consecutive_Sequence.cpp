// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp.insert(nums[i]);
        }
        
        for (int i = 0; i < n; i++)
        {
            int ele = nums[i];
            int curr_ans = 0;
            if (mpp.find(ele - 1) == mpp.end())
            {
                while (mpp.find(ele) != mpp.end())
                {
                    curr_ans++;
                    ele++;
                }
            }
            ans = max(ans, curr_ans);
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