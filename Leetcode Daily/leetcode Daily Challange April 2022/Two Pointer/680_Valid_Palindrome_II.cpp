// https://leetcode.com/problems/valid-palindrome-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'
class Solution
{
public:
    bool helper(string &str, int i, int j)
    {
        int s = i, e = j;
        while (s <= e)
        {
            if (str[s] != str[e])
            {
                return false;
            }

            s++, e--;
        }

        return true;
    }

    bool validPalindrome(string str)
    {
        int s = 0, e = str.size() - 1;
        while (s <= e)
        {
            if (str[s] != str[e])
            {
                return helper(str, s + 1, e) || helper(str, s, e - 1);
            }

            s++, e--;
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