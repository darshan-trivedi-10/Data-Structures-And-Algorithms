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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return head;
        }
        int sz = 1;
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            sz++;
        }

        k = k % sz;
        int n = sz - k;
        ListNode *mid = head;
        while ((n - 1) > 0)
        {
            mid = mid->next;
            n--;
        }

        temp->next = head;
        head = mid->next;
        mid->next = NULL;

        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}