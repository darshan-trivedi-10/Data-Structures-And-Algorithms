// https://leetcode.com/problems/balanced-binary-tree/
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxHeight(TreeNode *root, int &dimater)
    {
        if (root == NULL)
        {
            return 0;
        }

        int h1 = maxHeight(root->left, dimater);
        int h2 = maxHeight(root->right, dimater);
        dimater = max(dimater, abs(h1 - h2));

        return 1 + max(h1, h2);
    }

    bool isBalanced(TreeNode *root)
    {
        int dimater = 0;
        int depth = maxHeight(root, dimater);
        return dimater <= 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
