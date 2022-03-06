// https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void rightview(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == ans.size())
        {
            ans.push_back(root->val);
        }
        rightview(root->right, level + 1, ans);
        rightview(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        rightview(root, 0, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}