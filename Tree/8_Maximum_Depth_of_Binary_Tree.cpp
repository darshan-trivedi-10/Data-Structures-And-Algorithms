// https://leetcode.com/problems/maximum-depth-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Using DFS --> Tru to find depth of subtree + our root node
// Time Complexity : O(N), N = Number of Nodes 

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int h1 = maxDepth(root->left);
        int h2 = maxDepth(root->right);

        return 1 + max(h1, h2);
    }
};

// Using BFS --> Try to Find the Number of Level
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        ++res;
        for (int i = 0, n = q.size(); i < n; ++i)
        {
            TreeNode *p = q.front();
            q.pop();

            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}