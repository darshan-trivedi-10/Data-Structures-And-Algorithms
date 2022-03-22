// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.length();
        string ans = "";

        int cnt = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                ++cnt;
            }
            else if (s[i] == ')')
            {
                if (cnt == 0)
                {
                    s[i] = '.';
                }
                else
                {
                    --cnt;
                }
            }
        }

        cnt = 0;
        for (int i = n - 1; i >= 0; --i)
        {

            if (s[i] == ')')
            {
                ++cnt;
            }

            else if (s[i] == '(')
            {
                if (cnt == 0)
                {
                    s[i] = '.';
                }
                else
                {
                    --cnt;
                }
            }
        }

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != '.')
            {
                ans.push_back(s[i]);
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