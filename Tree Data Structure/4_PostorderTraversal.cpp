// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// left right root
class Solution
{
public:
    void postorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}