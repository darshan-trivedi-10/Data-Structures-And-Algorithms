// https://leetcode.com/problems/last-stone-weight/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y)
            {
                pq.push(x - y);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}