// https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class KthLargest
{
public:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> minheap;

    KthLargest(int k, vector<int> &nums)
    {
        m_k = k;
        for (int x : nums)
            add(x);
    }

    int add(int val)
    {
        if (minheap.size() < m_k)
            minheap.push(val);
        else
        {
            if (val > minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}