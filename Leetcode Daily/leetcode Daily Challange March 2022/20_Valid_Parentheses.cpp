// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty() || (st.top() == '(' && ch != ')') || (st.top() == '{' && ch != '}') || (st.top() == '[' && ch != ']'))
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.size() == 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
