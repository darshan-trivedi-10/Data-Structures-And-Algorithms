// https://leetcode.com/problems/increasing-order-search-tree/
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

class Solution
{

    TreeNode *inorder(TreeNode *root, TreeNode *tmp)
    {
        if (root == NULL)
        {
            return tmp;
        }
        tmp = inorder(root->left, tmp);
        tmp->right = root;
        root->left = NULL;
        tmp = tmp->right;
        return inorder(root->right, tmp);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *dummy = new TreeNode(0);
        TreeNode *tmp = dummy;
        inorder(root, tmp);
        return dummy->right;
    }
};

int main()
{

    return 0;
}