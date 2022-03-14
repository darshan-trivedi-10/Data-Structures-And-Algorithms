#include <bits/stdc++.h>
using namespace std;

//  Time Complexirt : O(2^n), Space Complexity : O(2^N)
int fibonacci(int n)
{
    //  Base Condition
    if (n < 2)
    {
        return n;
    }
    //  Recursive Call
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);

    return 0;
}