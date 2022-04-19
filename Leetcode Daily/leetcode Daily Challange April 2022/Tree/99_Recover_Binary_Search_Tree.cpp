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
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *firstMistake, *secondMistake, *pre;
    void recoverTree(TreeNode *root)
    {
        pre = new TreeNode(INT_MIN);
        inorder(root);
        swap(firstMistake->val, secondMistake->val);
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);

        if (firstMistake == NULL && root->val < pre->val)
        {
            firstMistake = pre;
        }
        if (firstMistake != NULL && root->val < pre->val)
        {
            secondMistake = root;
        }
        pre = root;

        inorder(root->right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}