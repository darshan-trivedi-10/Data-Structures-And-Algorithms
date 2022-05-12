// https://leetcode.com/problems/132-pattern/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

bool find132pattern(vector<int> &nums)
{
    int s3 = INT_MIN;
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] < s3)
        {
            return true;
        }
        else
        {
            while (!st.empty() && nums[i] > st.top())
            {
                s3 = st.top();
                st.pop();
            }
        }
        st.push(nums[i]);
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}