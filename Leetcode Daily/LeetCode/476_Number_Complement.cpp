// https://leetcode.com/problems/number-complement/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int findComplement(int num)
    {
        unsigned int ans = 0, t = 1;
        while (num > 0)
        {
            if (!(num & 1))
            {
                ans += t;
            }

            num = num / 2;
            t *= 2;
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