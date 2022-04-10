// https://leetcode.com/problems/baseball-game/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int n = ops.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            char ch = ops[i][0];
            if (ch >= '0' && ch <= '9')
            {
                st.push(stoi(ops[i]));
            }
            else
            {
                if (ch == 'C')
                {
                    st.pop();
                }
                else if (ch == 'D')
                {
                    int num = 2 * st.top();
                    st.push(num);
                }
                else if (ch == '+')
                {
                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.push(n1);
                    st.push(n1 + n2);
                }
            }
        }

        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> ops;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ops.push_back(s);
    }

    Solution obj;
    cout << obj.calPoints(ops) << endl;

    return 0;
}