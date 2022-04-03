// https://leetcode.com/problems/next-permutation/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        // next_permutation(arr.begin(), arr.end());
        int n = arr.size(), k, l;
        for (k = n - 2; k >= 0; k--)
        {
            if (arr[k] < arr[k + 1])
            {
                break;
            }
        }

        if (k < 0)
        {
            reverse(arr.begin(), arr.end());
        }
        else
        {
            for (l = n - 1; l > k; l--)
            {
                if (arr[l] > arr[k])
                {
                    break;
                }
            }
            swap(arr[k], arr[l]);
            reverse(arr.begin() + k + 1, arr.end());
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "Hi";

    return 0;
}