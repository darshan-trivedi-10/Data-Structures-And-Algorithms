
//   for preorder(we print the node when we touch for the first time,before touching left and right node),for inorder we print the node when we touch it for second time(after touching left node),for post order we print the node when we meet it for third time(after meeting left and right)..take a tree  with 3 nodes and apply pre,in and post order..see when we are printing the node for each traversal....Intution here is after how many visits we are printing the node.....(assume each node as a root  node)

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

// Time Complexity : O(N), Space Complexity : O(N).
class Solution
{
public:
    void inorderTraversal(TreeNode *root)
    {

        stack<pair<TreeNode *, int>> s;
        vector<int> pre, post, in;
        s.push({root, 1});
        if (root == NULL)
        {
            return;
        }
        while (!s.empty())
        {
            auto it = s.top();
            if (it.second == 1)
            {
                pre.push_back(it.first->val);
                s.top().second++;
                if (it.first->left != NULL)
                {
                    s.push({it.first->left, 1});
                }
            }
            else if (it.second == 2)
            {
                in.push_back(it.first->val);
                s.top().second++;
                if (it.first->right != NULL)
                {
                    s.push({it.first->right, 1});
                }
            }
            else
            {
                s.pop();
                post.push_back(it.first->val);
            }
        }
        for (int i = 0; i < pre.size(); i++)
        {
            cout << pre[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < in.size(); i++)
        {
            cout << in[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < post.size(); i++)
        {
            cout << post[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);

    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);

    s.inorderTraversal(t);

    return 0;
}