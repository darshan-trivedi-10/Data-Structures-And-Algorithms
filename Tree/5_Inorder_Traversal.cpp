// https://leetcode.com/problems/binary-tree-inorder-traversal/
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

// Time Complexity : O(N), Space Complexity : O(N).
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while (1)
        {
            if (node != NULL)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty() == true)
                {
                    break;
                }
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);

    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);

    vector<int> ans = s.inorderTraversal(NULL);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}