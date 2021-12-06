// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void rearrange(vector<int> &num)
    {
        int n = num.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (num[i] > num[i + 1])
            {
                swap(num[i], num[i + 1]);
            }
        }
    }
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int f = 0, s = 0;
        while (f < m and s < n)
        {
            if (nums1[f] <= nums2[s])
            {
                f++;
            }
            else
            {
                swap(nums1[f], nums2[s]);
                rearrange(nums2);
            }
        }

        while (s < n)
        {
            nums1[f] = nums2[s];
            f++, s++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}