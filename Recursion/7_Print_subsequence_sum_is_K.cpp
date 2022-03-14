// https://www.geeksforgeeks.org/find-all-subsequences-with-sum-equals-to-k/

/*
Given an array arr[] of length N and a number K, the task is to find all the subsequences of the array whose sum of elements is K

Examples:
Input: arr[] = {1, 2, 3}, K = 3
Output:
1 2
3

Input: arr[] = {17, 18, 6, 11, 2, 4}, K = 6
Output:
2 4
6
*/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

void printSubsequences(vector<int> &ds)
{
    int sz = ds.size();
    cout << "[ ";
    for (int i = 0; i < sz; i++)
    {
        cout << ds[i] << " ";
    }
    cout << " ]" << endl;
}

int CountSubsequences(vector<int> &arr, int sum, int k, int index)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    sum += arr[index];
    int l = CountSubsequences(arr, sum, k, index + 1);
    
    sum -= arr[index];
    int r = CountSubsequences(arr, sum, k, index + 1);

    return l + r;
}

bool findOneSubsequences(vector<int> &arr, vector<int> &ds, int sum, int k, int index)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            printSubsequences(ds);
            return true;
        }
        return false;
    }

    sum += arr[index];
    ds.push_back(arr[index]);
    if (findOneSubsequences(arr, ds, sum, k, index + 1))
    {
        return true;
    }
    // Backtracking
    sum -= arr[index];
    ds.pop_back();
    if (findOneSubsequences(arr, ds, sum, k, index + 1))
    {
        return true;
    }

    return false;
}

void findSubsequences(vector<int> &arr, vector<int> &ds, int sum, int k, int index)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            printSubsequences(ds);
        }
        return;
    }

    sum += arr[index];
    ds.push_back(arr[index]);
    findSubsequences(arr, ds, sum, k, index + 1);

    // Backtracking
    sum -= arr[index];
    ds.pop_back();
    findSubsequences(arr, ds, sum, k, index + 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ds(0);

    findSubsequences(arr, ds, 0, k, 0);

    return 0;
}