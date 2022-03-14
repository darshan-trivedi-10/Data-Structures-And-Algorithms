#include <bits/stdc++.h>
using namespace std;

bool check_Palindrome(string s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (s[start] != s[end])
    {
        return false;
    }

    return check_Palindrome(s, ++start, --end);
}

int main()
{
    string s;
    cin >> s;

    cout << check_Palindrome(s, 0, s.size() - 1);

    return 0;
}