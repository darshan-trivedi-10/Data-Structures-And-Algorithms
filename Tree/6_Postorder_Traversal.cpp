// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity : O(N), Space Complexity : O(2*N).
// Using Two Stack
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left != NULL)
            {
                s1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                s1.push(temp->right);
            }
        }

        while (!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }

        return ans;
    }
};

// Time Complexity : O(N), Space Complexity : O(1).
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s1;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            ans.push_back(temp->val);
            if (temp->left != NULL)
            {
                s1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                s1.push(temp->right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}