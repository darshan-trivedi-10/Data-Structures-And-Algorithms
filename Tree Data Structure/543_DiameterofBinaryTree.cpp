// https://leetcode.com/problems/diameter-of-binary-tree/

#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxDiameter(TreeNode *root, int &diameter)
    {
        if (root == NULL)
        {
            return 0;
        }

        int h1 = maxDiameter(root->left, diameter);
        int h2 = maxDiameter(root->right, diameter);
        diameter = max(diameter, h1 + h2);

        return 1 + max(h1, h2);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        maxDiameter(root, diameter);
        return diameter;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}