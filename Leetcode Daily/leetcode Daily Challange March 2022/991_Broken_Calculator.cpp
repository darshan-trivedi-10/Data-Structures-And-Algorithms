// https://leetcode.com/problems/broken-calculator/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int ans = 0;
        while (target > startValue)
        {
            if (target & 1)
            {
                target++;
            }
            else
            {
                target /= 2;
            }

            ans++;
        }

        return ans + startValue - target;
    }
};

int main()
{

    return 0;
}