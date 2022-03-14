/*
You Are Given number N, Print the factorial pf number  N.
Input : N = 5
Output :  120

*/
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);

    return 0;
}