// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

int maxLen(vector<int> &arr, int n)
{
    unordered_map<int, int> mpp;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            ans = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                ans = max(ans, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}