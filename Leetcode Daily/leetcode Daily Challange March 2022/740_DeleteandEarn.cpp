// https://leetcode.com/problems/delete-and-earn/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int t[20001];
    int solve(vector<int> &arr, int i)
    {
        if (i >= arr.size())
        {
            return 0;
        }

        if (t[i] != -1)
        {
            return t[i];
        }

        int currValue = arr[i];
        int currSum = arr[i];
        int index = i + 1;

        while (index < arr.size() && arr[index] == currValue)
        {
            currSum += arr[i];
            index++;
        }

        while (index < arr.size() && arr[index] == currValue + 1)
        {
            index++;
        }

        return t[i] = max(currSum + solve(arr, index), solve(arr, i + 1));
    }
    int deleteAndEarn(vector<int> &arr)
    {
        int n = arr.size();
        memset(t, -1, sizeof(t));
        sort(arr.begin(), arr.end());

        return solve(arr, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}