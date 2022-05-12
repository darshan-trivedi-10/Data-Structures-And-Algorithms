// https://leetcode.com/problems/implement-stack-using-queues/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class MyStack
{
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int data)
    {
        if (!q1.empty())
        {
            q1.push(data);
        }
        else
        {
            q2.push(data);
        }
    }

    int pop()
    {
        int element;
        if (!q1.empty())
        {
            while (!q1.empty())
            {
                element = q1.front();
                if (q1.size() != 1)
                {
                    q2.push(element);
                }
                q1.pop();
            }
        }
        else
        {
            while (!q2.empty())
            {
                element = q2.front();
                if (q2.size() != 1)
                {
                    q1.push(element);
                }
                q2.pop();
            }
        }
        return element;
    }

    int top()
    {
        int ans;
        if (!q1.empty())
        {
            while (!q1.empty())
            {
                ans = q1.front();
                q2.push(ans);
                q1.pop();
            }
        }
        else
        {
            while (!q2.empty())
            {
                ans = q2.front();
                q1.push(ans);
                q2.pop();
            }
        }
        return ans;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}