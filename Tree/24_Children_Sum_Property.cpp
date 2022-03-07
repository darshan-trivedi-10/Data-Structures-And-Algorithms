// https://www.techiedelight.com/fix-children-sum-property-binary-tree/
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
// Time Complexity O(N), Space Complexity : O(N);
    void fixsumProperty(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        int child = 0;
        if (root->left)
        {
            child += root->left->val;
        }
        if (root->right)
        {
            child += root->right->val;
        }

        if (child >= root->val)
        {
            root->val = child;
        }
        else
        {
            if (root->left)
            {
                root->left->val = root->val;
            }

            if (root->right)
            {
                root->right->val = root->val;
            }
        }

        fixsumProperty(root->left);
        fixsumProperty(root->right);
        int sum = 0;
        if (root->left)
        {
            sum += root->left->val;
        }
        if (root->right)
        {
            sum += root->right->val;
        }

        if (root->left || root->right)
        {
            root->val = sum;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}