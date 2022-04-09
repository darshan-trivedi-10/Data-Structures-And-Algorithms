// https://leetcode.com/problems/top-k-frequent-elements/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto it : mpp)
        {
            pq.push({it.second, it.first});
            if (pq.size() > (int(mpp.size() - k)))
            {
                ans.push_back(pq.top().second);
                pq.pop();
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