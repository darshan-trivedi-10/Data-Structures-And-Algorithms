#include <bits/stdc++.h>
using namespace std;

//  Time Complexirt : O(2^n), Space Complexity : O(2^N)
void revese_array(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    swap(arr[s], arr[e]);
    revese_array(arr, ++s, --e);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    revese_array(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}