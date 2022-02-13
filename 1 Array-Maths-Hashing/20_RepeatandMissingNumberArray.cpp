// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

int findSetbit(int num1)
{
    int setBitPos = 0;
    while (num1 > 0)
    {
        int cbnum1 = (num1 & 1);
        if (cbnum1 == 1)
        {
            return setBitPos;
        }
        setBitPos++;
    }

    return setBitPos;
}

// First Sol :-  Using Soring
// Second Sol :- Using HashMap
/*
Third Sol :-
Sum of all elements from 1 to N:
S = N*(N+1)/2 ---- equation 1
And, Sum of squares of all elements from 1 to N:
P = N(N+1)(2N+1)/6. ----- equation 2

Similarly, find the sum of all elements of the array and sum of squares of all elements of the array respectively.

s1 = Sum of all elements of the array. —– equation 3
P1 = Sum of squares of all elements of the array. ——– equation 4

Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y).

Therefore,

(X-Y) = s – s1 = s’
Similarily,
X^2 – Y^2 = P – P1 = P’
or, (X + Y)(X – Y) = P’
or, (X + Y)*s’ = P’
or, X + Y = P’/s’

Great,
we have the two equations we needed:
(X – Y) = s’
(X + Y) = P’/s’

We can use the two equations to solve and find values for X and Y respectively.
Note: here s and P can be large so take long long int data type.
*/

// Fourth Sol :- Using Xor

vector<int> repeatedNumber(const vector<int> &a)
{
    int setBitNo;
    int x = 0, y = 0;
    int n = a.size();
    int xor1 = 0;

    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    setBitNo = xor1 & (~(xor1 - 1));
    for (int i = 0; i < n; i++)
    {
        if (a[i] & setBitNo)
        {
            x = x ^ a[i];
        }
        else
        {
            y = y ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & setBitNo)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }

    int xCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            xCount++;
        }
    }

    if (xCount == 0)
    {
        return {y, x};
    }

    return {x, y};
}



int main()
{

    return 0;
}