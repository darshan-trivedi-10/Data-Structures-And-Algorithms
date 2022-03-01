// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// left root right
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}