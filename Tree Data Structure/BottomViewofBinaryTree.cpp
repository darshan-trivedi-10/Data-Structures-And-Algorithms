// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Node
{
    int data;
    Node *left;
    Node *right;
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

        map<int, int> mpp; // First value is vertical level & second value is val.

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                auto p = q.front();
                q.pop();
                Node *temp = p.first;
                int line = p.second;
                if (mpp.find(line) == mpp.end())
                {
                    mpp[line] = temp->data;
                }
                else
                {
                    mpp[line] = temp->data;
                }

                if (temp->left)
                {
                    q.push({temp->left, line - 1});
                }

                if (temp->right)
                {
                    q.push({temp->right, line + 1});
                }
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