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

// Time Complexity : O((log(n)^2)), Space Complexity : O(log(n)).
class Solution
{
public:
    int findleftHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->left;
            height++;
        }
        return height;
    }

    int findrightHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->right;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = findleftHeight(root);
        int rh = findrightHeight(root);
        if (lh == rh)
        {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Time Complexity : O(N)
class Solution
{
public:
    int count(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = count(root->left);
        int right = count(root->right);

        return 1 + left + right;
    }
    int countNodes(TreeNode *root)
    {
        return count(root);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}