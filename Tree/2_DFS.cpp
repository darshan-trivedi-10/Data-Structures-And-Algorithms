#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'
struct node
{
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// left root right
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Root , left, right Time Complexity O(N), Space Complexity O(N) (If tree is Skewed Tree)
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// left right root
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(8);
    root->right->right = new node(6);
    root->right->left = new node(7);
    preorder(root); // 1 2 8 5 3 7 6
    cout << endl;
    inorder(root); // 8 2 5 1 7 3 6
    cout << endl;

    /*
                      1
                  /     \
                2        3
             /    \    /  \
           8       5  7   6
   */

    return 0;
}