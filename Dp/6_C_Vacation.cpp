#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct triplet
{
    int a, b, c;
};

int getHappiness(triplet happiness, int i)
{
    return (i == 0 ? happiness.a : (i == 1 ? happiness.b : happiness.c));
}

// Recursion + Memorizastion
int findMaxHappiness(vector<triplet> &arr, vector<vector<int>> &dp, int idx, int prevActivity, int n)
{
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][prevActivity] != -1)
    {
        return dp[idx][prevActivity];
    }

    int maxHappines = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (prevActivity != i)
        {
            int currHappiness = findMaxHappiness(arr, dp, idx + 1, i, n) + getHappiness(arr[idx], i);
            maxHappines = max(maxHappines, currHappiness);
        }
    }

    return dp[idx][prevActivity] = maxHappines;
}


//  Using Tabulastion
int findMaxHappiness(vector<triplet> &arr, vector<vector<int>> &dp, int n){
    
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = arr[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

int main()
{
    int n;
    cin >> n;
    vector<triplet> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }

    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << findMaxHappiness(arr, dp, 0, 3, n);

    return 0;
}
