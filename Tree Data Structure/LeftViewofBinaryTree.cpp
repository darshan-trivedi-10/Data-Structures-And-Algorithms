// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void leftViewFinder(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    leftViewFinder(root->left, level + 1, ans);
    leftViewFinder(root->right, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    leftViewFinder(root, 0, ans);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}