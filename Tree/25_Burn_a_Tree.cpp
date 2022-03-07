// https://www.interviewbit.com/problems/burn-a-tree/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

//  Definition for binary tree
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *TreeNode_new(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *markparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, int target)
{
    TreeNode *res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current->val == target)
        {
            res = current;
        }
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

    return res;
}

int findtime(TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parent_track)
{
    int ans = 0;
    queue<TreeNode *> q;
    q.push(target);
    unordered_map<TreeNode *, bool> vis;
    vis[target] = true;
    while (!q.empty())
    {
        int size = q.size();
        bool burn = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left && !vis[temp->left])
            {
                burn = 1;
                vis[temp->left] = true;
                q.push(temp->left);
            }

            if (temp->right && !vis[temp->right])
            {
                burn = 1;
                vis[temp->right] = true;
                q.push(temp->right);
            }
            TreeNode *parent = parent_track[temp];
            if (parent && !vis[parent])
            {
                burn = 1;
                q.push(parent);
                vis[parent] = true;
            }
        }
        if (burn)
        {
            ans++;
        }
    }
    return ans;
}

int solve(TreeNode *root, int num)
{
    unordered_map<TreeNode *, TreeNode *> parent_track;
    TreeNode *target = markparent(root, parent_track, num);
    return findtime(target,parent_track);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}