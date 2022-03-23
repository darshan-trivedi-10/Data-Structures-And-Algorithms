// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/
// Problem Link :- https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'
#define INT_MAX 2147483647

// TC :- O(N) , SC :- O(N) + O(N)
// Memorization
int findMinEnegry(vector<int> &heights, vector<int> &dp, int index)
{
    if (index == 0)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int jumpTwo = INT_MAX;
    int jumpOne = findMinEnegry(heights, dp, index - 1) + abs(heights[index] - heights[index - 1]);
    if (index > 1)
    {
        jumpTwo = findMinEnegry(heights, dp, index - 2) + abs(heights[index] - heights[index - 2]);
    }

    return dp[index] = min(jumpOne, jumpTwo);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return findMinEnegry(heights, dp, n - 1);
}

// Tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int one = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int two = INT_MAX;
        if (i > 1)
        {
            two = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(one, two);
    }
    return dp[n - 1];
}

// Tabulation with space optimization
// TC :- O(N), SC :- O(1)
int frogJump(int n, vector<int> &heights)
{
    int prev = 0, prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int one = prev + abs(heights[i] - heights[i - 1]);
        int two = INT_MAX;
        if (i > 1)
        {
            two = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curr = min(one, two);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    
    return 0;
}