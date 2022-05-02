// https://leetcode.com/problems/backspace-string-compare/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        int count = 0;
        int s1 = n1, s2 = n2;
        for (int i = n1 - 1; i >= 0; i--)
        {
            if (s[i] == '#')
            {
                count++;
                s1--;
            }
            else if (count > 0)
            {
                count--;
                s1--;
                s[i] = '#';
            }
        }
        count = 0;
        for (int i = n2 - 1; i >= 0; i--)
        {
            if (t[i] == '#')
            {
                count++;
                s2--;
            }
            else if (count > 0)
            {
                count--;
                s2--;
                t[i] = '#';
            }
        }

        if (s1 != s2)
        {
            return false;
        }

        int i = 0, j = 0;
        while (s1 > 0 && s2 > 0)
        {
            if (s[i] == '#')
            {
                i++;
            }
            else if (t[j] == '#')
            {
                j++;
            }
            else
            {
                if (s[i] != t[j])
                {
                    return false;
                }
                s1--, s2--;
                i++, j++;
            }
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}