// https://leetcode.com/problems/smallest-integer-divisible-by-k/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

/*
Time  Complexity:O(k)
Space Complexity:O(1)
*/
class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        // n % k == 0 , n only contain digit 1
        if (k % 2 == 0 || k % 5 == 0)
        {
            return -1;
        }
        int perv_rem = 0;
        int ans = -1;
        for (int i = 1; i <= k; i++)
        {
            perv_rem = (perv_rem * 10 + 1) % k;
            if (perv_rem == 0)
            {
                ans = i;
                break;
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