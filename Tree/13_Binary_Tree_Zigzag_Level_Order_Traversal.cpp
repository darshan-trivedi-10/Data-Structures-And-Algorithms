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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> nodes;
        nodes.push(root);
        bool leftright = true;
        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<int> t(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = nodes.front();
                nodes.pop();

                int index = (leftright ? i : (size - i - 1));

                if (temp->left != NULL)
                {
                    nodes.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    nodes.push(temp->right);
                }
                t[index] = temp->val;
            }

            leftright = !leftright;
            ans.push_back(t);
        }

        return ans;
    }
};

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

        queue<TreeNode *> nodes;
        nodes.push(root);
        int d = 0;
        while (!nodes.empty())
        {
            vector<int> t;
            int size = nodes.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = nodes.front();
                nodes.pop();
                if (temp->left != NULL)
                {
                    nodes.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    nodes.push(temp->right);
                }
                t.push_back(temp->val);
            }
            if (d & 1)
            {
                reverse(t.begin(), t.end());
            }
            ans.push_back(t);
            d++;
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