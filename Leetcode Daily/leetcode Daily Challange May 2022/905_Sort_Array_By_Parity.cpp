#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int even = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[i], nums[even]);
                even++;
            }
        }

        return nums;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}