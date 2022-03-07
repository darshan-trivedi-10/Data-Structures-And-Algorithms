#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Time Complexity : O(N), Space Complexity : (O(N) ---> In worst Case).
class Solution
{
public:
    void rightview(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == ans.size())
        {
            ans.push_back(root->val);
        }
        rightview(root->right, level + 1, ans);
        rightview(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        rightview(root, 0, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}