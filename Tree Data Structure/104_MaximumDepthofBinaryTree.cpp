// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <bits/stdc++.h>
#include "tree.h"

using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int h1 = maxDepth(root->left);
        int h2 = maxDepth(root->right);

        return 1 + max(h1, h2);
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}