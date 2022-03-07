// https://leetcode.com/problems/diameter-of-binary-tree/  
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

class Solution
{
public:
    int maxDepth(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int h1 = maxDepth(root->left, maxi);
        int h2 = maxDepth(root->right, maxi);
        maxi = max(maxi, h1 + h2);

        return 1 + max(h1, h2);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        maxDepth(root, ans);
        return ans;
    }
};

// Time Complexity : O(N^2)
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
    int solve(TreeNode *root, int ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        ans = max(ans, lh + rh);
        int a = solve(root->left, ans);
        int b = solve(root->right, ans);

        return max(ans, max(a, b));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        return solve(root, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}