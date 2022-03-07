// https://leetcode.com/problems/validate-binary-search-tree/
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

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *cur = root;
        bool isValid = true;
        bool firsttime = 1;
        int prev_ele = INT_MIN;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                if (cur->val <= prev_ele && !firsttime)
                {
                    isValid = false;
                }
                firsttime = false;
                prev_ele = cur->val;
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = NULL;
                    if (cur->val <= prev_ele && !firsttime)
                    {
                        isValid = false;
                    }
                    firsttime = false;
                    prev_ele = cur->val;
                    cur = cur->right;
                }
            }
        }
        return isValid;
    }
};
int main()
{

    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(4);
    // root->left->left = NULL;
    // root->left->right = NULL;

    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(6);
    // root->right->left->left = root->right->left->right = NULL;

    // root->right->right->left = root->right->right->right = NULL;

    return 0;
}