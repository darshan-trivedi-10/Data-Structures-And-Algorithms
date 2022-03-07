// https://leetcode.com/problems/symmetric-tree/
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
    bool checksymmetric(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
        {
            return left == right;
        }

        if (left->val != right->val)
        {
            return false;
        }

        bool l = checksymmetric(left->left, right->right);
        bool r = checksymmetric(left->right, right->left);

        return l & r;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return checksymmetric(root->left, root->right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}