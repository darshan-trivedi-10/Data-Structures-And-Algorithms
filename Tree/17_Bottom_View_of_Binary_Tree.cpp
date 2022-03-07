// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        // First value store their vertical level  and second value store their value
        map<int, int> mpp;
        // First value store node address, and second value store their vertical level.
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node *temp = p.first;
            int line = p.second;
            mpp[line] = temp->data;
            if (temp->left)
            {
                q.push({temp->left, line - 1});
            }
            if (temp->right)
            {
                q.push({temp->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
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