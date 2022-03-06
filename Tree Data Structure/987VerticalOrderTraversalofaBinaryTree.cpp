// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // Map is store vertical, (level, multi nodes).
        map<int, map<int, multiset<int>>> node;
        // Node, vertical & their level
        queue<pair<TreeNode *, pair<int, int>>> t;
        t.push({root, {0, 0}});
        while (!t.empty())
        {
            auto p = t.front();
            t.pop();
            TreeNode *n = p.first;
            int x, y;
            x = p.second.first, y = p.second.second;
            node[x][y].insert(n->val);
            if (n->left)
            {
                t.push({n->left, {x - 1, y + 1}});
            }
            if (n->right)
            {
                t.push({n->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : node)
        {
            vector<int> c;
            for (auto i : p.second)
            {
                c.insert(c.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(c);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}