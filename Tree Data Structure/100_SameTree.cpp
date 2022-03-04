// https://leetcode.com/problems/same-tree/
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL)
        {
            return p == q;
        }

        int pVal = p->val, qVal = q->val;

        return (pVal == qVal && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}