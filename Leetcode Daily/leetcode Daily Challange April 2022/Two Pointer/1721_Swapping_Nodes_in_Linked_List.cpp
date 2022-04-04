// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int sz = 0;
        ListNode *temp = head;
        ListNode *l1 = head, *l2 = head;
        while (temp != NULL)
        {
            sz++;
            temp = temp->next;
        }
        sz = sz - k;
        while (sz != 0)
        {
            l1 = l1->next;
            sz--;
        }

        while (k != 1)
        {
            l2 = l2->next;
            k--;
        }

        swap(l1->val, l2->val);
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}