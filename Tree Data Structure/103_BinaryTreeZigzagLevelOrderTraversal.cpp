// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        bool leftRight = true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> temp(sz);
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int index = leftRight ? i : (sz - i - 1);

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }

                temp[index] = node->val;
            }
            leftRight = !leftRight;
            ans.push_back(temp);
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