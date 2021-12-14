#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int find = target - nums[i] - nums[j];

                int s = j + 1, e = n - 1;
                while (s < e)
                {
                    int ts = nums[s] + nums[e];
                    if (ts == find)
                    {
                        vector<int> temp(4, 0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[s];
                        temp[3] = nums[e];
                        ans.push_back(temp);
                        while (s < e && nums[s] == temp[2])
                        {
                            s++;
                        }

                        while (s < e && nums[e] == temp[3])
                        {
                            e--;
                        }
                    }
                    else if (ts < find)
                    {
                        s++;
                    }
                    else
                    {
                        e--;
                    }

                    while ((j + 1) < n && nums[j + 1] == nums[j])
                    {
                        j++;
                    }

                    while ((i + 1) < n && nums[i + 1] == nums[i])
                    {
                        i++;
                    }
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