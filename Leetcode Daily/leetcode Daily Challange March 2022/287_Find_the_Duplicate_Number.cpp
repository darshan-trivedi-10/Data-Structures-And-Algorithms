#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast = nums[0];
        int slow = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}