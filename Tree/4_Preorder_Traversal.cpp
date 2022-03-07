// https://leetcode.com/problems/binary-tree-preorder-traversal/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

//  Definition for a binary tree node.
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
    // Time Complexity : O(N), Space Complexity : O(N) =~ O(Height of BT)
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *a = s.top();
            ans.push_back(a->val);
            s.pop();
            if (a->right != NULL)
            {
                s.push(a->right);
            }
            if (a->left != NULL)
            {
                s.push(a->left);
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}