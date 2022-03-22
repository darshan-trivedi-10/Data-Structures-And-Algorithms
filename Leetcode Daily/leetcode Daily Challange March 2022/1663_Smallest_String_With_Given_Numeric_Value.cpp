// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string ans(n, 'a');
        k -= n;
        while (k > 0)
        {
            ans[--n] += min(25, k);
            k -= min(25, k);
        }
        return ans;
    }
};

int main()
{

    return 0;
}