// https://leetcode.com/problems/simplify-path/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        for(int i = 0;  i<path.size(); ++i)
        {
            if(path[i] == '/'){
                continue;
            }
            
            string temp;
            while(i < path.size() && path[i] != '/')
            {
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(temp);
        }
        
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}