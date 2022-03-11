// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int carry = 0;

        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;

        while (l1 != NULL && l2 != NULL)
        {
            int d1 = l1->val;
            int d2 = l2->val;

            int num = d1 + d2 + carry;
            ptr->next = new ListNode(num % 10);
            carry = num / 10;

            l1 = l1->next;
            l2 = l2->next;
            ptr = ptr->next;
        }

        while (l1 != NULL)
        {
            int d1 = l1->val;
            int num = d1 + carry;
            ptr->next = new ListNode(num % 10);
            carry = num / 10;

            l1 = l1->next;
            ptr = ptr->next;
        }

        while (l2 != NULL)
        {
            int d1 = l2->val;
            int num = d1 + carry;
            ptr->next = new ListNode(num % 10);
            carry = num / 10;

            l2 = l2->next;
            ptr = ptr->next;
        }

        while (carry > 0)
        {
            ptr->next = new ListNode(carry % 10);
            carry /= 10;
            ptr = ptr->next;
        }

        return dummy->next;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}