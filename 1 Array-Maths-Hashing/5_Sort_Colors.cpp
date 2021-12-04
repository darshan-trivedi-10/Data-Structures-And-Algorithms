// https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int i = 0, j = arr.size() - 1;
        int k = 0;
        while (k <= j)
        {
            if (arr[k] == 1)
            {
                k++;
            }
            else if (arr[k] == 0)
            {
                swap(arr[k], arr[i]);
                k++, i++;
            }
            else if (arr[k] == 2)
            {
                swap(arr[k], arr[j]);
                j--;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}