// https://leetcode.com/problems/container-with-most-water/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxArea(vector<int> &arr)
    {
        int n = arr.size();
        int area = 0;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int currArea = min(arr[left], arr[right]) * (right - left);
            area = max(area, currArea);
            if (arr[left] < arr[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return area;
    }
};

int main()
{

    return 0;
}