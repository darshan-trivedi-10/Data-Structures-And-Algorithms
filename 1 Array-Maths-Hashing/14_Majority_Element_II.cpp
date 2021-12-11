#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// Time Complexity : O(N) + O(N).
// Space Complexity : O(1).
// Time Complexity : O(N) + O(N).
// Space Complexity : O(1).
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int a1 = -1, a2 = -1;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            int ele = nums[i];
            if (ele == a1)
            {
                c1++;
            }
            else if (ele == a2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                a1 = ele;
                c1++;
            }
            else if (c2 == 0)
            {
                a2 = ele;
                c2++;
            }
            else
            {
                c1--, c2--;
            }
        }

        c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            int ele = nums[i];
            if (a1 == ele)
            {
                c1++;
            }
            else if (a2 == ele)
            {
                c2++;
            }
        }

        int sz = (nums.size() / 3);
        c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a1 == nums[i])
            {
                c1++;
            }
            else if (a2 == nums[i])
            {
                c2++;
            }
        }

        vector<int> ans;
        if (c1 > sz)
        {
            ans.push_back(a1);
        }
        if (c2 > sz)
        {
            ans.push_back(a2);
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