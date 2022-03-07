#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

//  Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool givePath(TreeNode *root, int B, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->val == B)
    {
        ans.push_back(root->val);
        return true;
    }

    ans.push_back(root->val);
    bool left = givePath(root->left, B, ans);
    if (left)
    {
        return true;
    }
    bool right = givePath(root->right, B, ans);
    if (right)
    {
        return true;
    }
    ans.pop_back();
    return false;
}


vector<int> solve(TreeNode *root, int B)
{
    vector<int> ans;
    givePath(root, B, ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}