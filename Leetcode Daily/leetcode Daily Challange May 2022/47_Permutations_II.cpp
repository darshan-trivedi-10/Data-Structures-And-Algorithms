// https://leetcode.com/problems/permutations-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;
        arr.push_back(nums);

        while (next_permutation(nums.begin(), nums.end()))
        {
            arr.push_back(nums);
        }

        return arr;
    }
};

int main()
{

    return 0;
}