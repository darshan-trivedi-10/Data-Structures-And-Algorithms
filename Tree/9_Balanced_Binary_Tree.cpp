// https://leetcode.com/problems/balanced-binary-tree/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

//   Definition for a binary tree node.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Aprooche 1
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
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        if (abs(lh - rh) > 1)
        {
            return false;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        return left & right;
    }
};

class Solution
{
public:
    // Time Complexity : O(N)
    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int h1 = dfsHeight(root->left);
        if (h1 == -1)
        {
            return h1;
        }
        int h2 = dfsHeight(root->right);
        if (h2 == -1)
        {
            return h2;
        }
        if (abs(h1 - h2) > 1)
        {
            return -1;
        }

        return 1 + max(h1, h2);
    }
    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);

    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);

    return 0;
}

