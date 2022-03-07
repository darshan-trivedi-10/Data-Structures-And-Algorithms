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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *cur = root;
        TreeNode *add = new TreeNode(val);
        if (cur == NULL)
        {
            return add;
        }

        while (1)
        {
            if (cur->val <= val)
            {
                if (cur->right != NULL)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = add;
                    break;
                }
            }
            else
            {
                if (cur->left != NULL)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = add;
                    break;
                }
            }
        }
        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}