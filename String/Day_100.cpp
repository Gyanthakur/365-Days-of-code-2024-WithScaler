// https://www.interviewbit.com/problems/reverse-the-string/

#include <bits/stdc++.h>
using namespace std;

string solve(string A)
{
    stack<string> st;
    int n = A.length();
    string ans;
    for (int i = 0; i < n; i++)
    {

        if (A[i] >= 97 && A[i] <= 122)
        {
            string s;
            while ((A[i] >= 97 && A[i] <= 122) && i < n)
            {
                s += A[i];
                i++;
            }
            st.push(s);
        }
        else
            continue;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        if (!st.empty())
            ans += " ";
    }
    return ans;
}