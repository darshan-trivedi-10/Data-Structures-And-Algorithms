#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// Time Complexity : O(N)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int candidate = -1;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                candidate = nums[i];
            }

            if (candidate == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}