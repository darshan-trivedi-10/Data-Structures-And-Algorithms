// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 0)
        {
            return ans;
        }

        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                temp[1] = max(temp[1], it[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }

        ans.push_back(temp);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}