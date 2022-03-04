// https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxPath(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = max(0, maxPath(root->left, maxi));
        int right = max(0, maxPath(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        int temp = maxPath(root, maxi);
        return maxi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}