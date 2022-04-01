// https://leetcode.com/problems/reverse-string/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void reverseString(vector<char> &str)
    {
        int s = 0, e = str.size();
        while (s < e)
        {
            swap(str[s], str[e]);
            s++, e--;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}