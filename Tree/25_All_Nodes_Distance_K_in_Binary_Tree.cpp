// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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

class Solution
{
public:
    void markparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left)
            {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right)
            {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    void give_nodes(vector<int> &ans, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target, int k)
    {
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> visited;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (curr_level == k)
            {
                break;
            }

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                if (current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if (current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                TreeNode *parent = parent_track[current];
                if (parent && !visited[parent])
                {
                    q.push(parent);
                    visited[parent] = true;
                }
            }
            curr_level++;
        }

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        markparent(root, parent_track, target);

        vector<int> ans;
        give_nodes(ans, parent_track, target, k);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}