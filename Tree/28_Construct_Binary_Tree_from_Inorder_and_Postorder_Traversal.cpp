// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode *buildtreepostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &mpp)
    {
        if (is > ie || ps > pe)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[pe]);
        int ri = mpp[postorder[pe]];
        TreeNode *leftChild = buildtreepostIn(inorder, is, ri - 1, postorder, ps, ps + ri - is - 1, mpp);
        TreeNode *rightChild = buildtreepostIn(inorder, ri + 1, ie, postorder, ps + ri - is, pe - 1, mpp);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
        {
            return NULL;
        }

        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        return buildtreepostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}