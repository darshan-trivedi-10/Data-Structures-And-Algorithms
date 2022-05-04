// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        int maxe = 0, mine = n - 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[maxe])
            {
                maxe = i;
            }
            else if (nums[i] < nums[maxe])
            {
                l = i;
            }

            if (nums[n - i - 1] < nums[mine])
            {
                mine = n - i - 1;
            }
            else if (nums[n - i - 1] > nums[mine])
            {
                r = n - i - 1;
            }
        }

        return (r >= l ? 0 : (l - r + 1));
    }
};

int main()
{

    return 0;
}