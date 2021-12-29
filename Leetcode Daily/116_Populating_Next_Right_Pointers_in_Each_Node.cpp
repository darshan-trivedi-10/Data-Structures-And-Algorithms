// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Using Recursion

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root->left)
        {
            root->left->next = root->right;
        }

        if (root->right && root->next)
        {
            root->right = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};

// Using BFS
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return root;
        }

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (i != (sz - 1))
                {
                    Node *tt = q.front();
                    temp->next = tt;
                }

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}