// https://leetcode.com/problems/powx-n/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'


// Time Complexity : O(log(N)).
class Solution
{
public:
    using lli = long long int;
    double binary_exponentiation(double a, lli b)
    {
        double ans = 1;
        // if(b%2==1) this means number b is odd.
        while (b)
        {
            if (b & 1)
            {
                ans = (ans * a);
            }
            a = (a * a);
            b = (b >> 1);
        }

        return ans;
    }

    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
        {
            nn *= -1;
        }

        ans = binary_exponentiation(x, nn);

        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
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
