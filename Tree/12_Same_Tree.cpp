// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }
        bool leftcheck = isSameTree(p->left, q->left);
        bool rightcheck = isSameTree(p->right, q->right);
        return leftcheck & rightcheck;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}