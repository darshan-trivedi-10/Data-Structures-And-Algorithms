#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    struct node *root = new node(1);
    /*
                  1
    */
    root->left = new node(2);
    /*
                   1
                /
            2
   */
    root->right = new node(3);
    /*
                 1
              /   \
            2      3
    */
    root->left->right = new node(5);
    /*
                  1
               /   \
             2      3
              \
                5
  */

    return 0;
}