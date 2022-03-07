// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    // Time Complexity : O(N).
    int maxsum(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftsum = max(0, maxsum(root->left, maxi));
        int rightsum = max(0, maxsum(root->right, maxi));
        maxi = max(maxi, leftsum + rightsum + root->val);

        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = 0;
        int ans = maxsum(root, maxi);
        return maxi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}