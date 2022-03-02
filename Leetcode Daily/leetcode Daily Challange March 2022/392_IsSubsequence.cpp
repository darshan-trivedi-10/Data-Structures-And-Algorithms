// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (s[i] == t[j])
            {
                i++, j++;
            }
            else
            {
                j++;
            }
        }

        return i == n1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}