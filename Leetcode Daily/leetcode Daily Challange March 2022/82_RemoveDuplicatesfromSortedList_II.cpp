// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head, *prev = NULL;
        while (temp != NULL)
        {
            bool check = 1;
            while (temp->next && temp->val == temp->next->val)
            {
                if (check)
                {
                    check = !check;
                }
                temp = temp->next;
            }

            if (check)
            {
                prev = temp;
                temp = temp->next;
            }
            else
            {
                if (prev == NULL)
                {
                    head = temp->next;
                    temp = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                    temp = temp->next;
                }
            }
        }

        return head;
    }
};




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}