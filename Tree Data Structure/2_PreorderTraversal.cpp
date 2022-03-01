// https://leetcode.com/problems/binary-tree-preorder-traversal/
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}