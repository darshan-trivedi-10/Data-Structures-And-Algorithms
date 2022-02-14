// https://leetcode.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>
#include "ll.h"
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *newLL = NULL;
        ListNode *l1 = list1, *l2 = list2;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                if (!newLL)
                {
                    newLL = l2;
                }
                else
                {
                    newLL->next = l2;
                    newLL = newLL->next;
                }
                l2 = l2->next;
            }
            else
            {
                if (!newLL)
                {
                    newLL = l1;
                }
                else
                {
                    newLL->next = l1;
                    newLL = newLL->next;
                }
                l1 = l1->next;
            }
        }

        while (l2)
        {
            if (!newLL)
            {
                newLL = l2;
            }
            else
            {
                newLL->next = l2;
                newLL = newLL->next;
            }
            l2 = l2->next;
        }

        while (l1)
        {
            if (!newLL)
            {
                newLL = l1;
            }
            else
            {
                newLL->next = l1;
                newLL = newLL->next;
            }
            l1 = l1->next;
        }

        return newLL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}