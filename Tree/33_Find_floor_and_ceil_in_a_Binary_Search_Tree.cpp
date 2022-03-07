// https://www.techiedelight.com/floor-ceil-bst-iterative-recursive/

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
    // val >= key
    // Time Complexity : O(log2(N)).
    int ceilInBST(TreeNode *root, int key)
    {
        int ceil = -1;
        while (root)
        {
            if (root->val == key)
            {
                ceil = root->val;
                break;
            }

            if (ceil > root->val)
            {
                root = root->right;
            }
            else
            {
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }

    int floorInBST(TreeNode *root, int key)
    {
        // key >= val
        int floor = -1;
        while (root)
        {
            if (root->val == key)
            {
                floor = root->val;
                break;
            }

            if (floor > root->val)
            {
                floor = root->val;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floor;
    } 
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}