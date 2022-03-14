#include <bits/stdc++.h>
using namespace std;

int b_search(vector<int> &arr, int key, int s, int e)
{
    // int e = arr.size() - 1;/
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        e = mid - 1;
    }
    else
    {
        s = mid + 1;
    }

    if (s <= e)
    {
        return -1;
    }

    return b_search(arr, key, s, e);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << b_search(arr, key, 0, arr.size() - 1);

    return 0;
}