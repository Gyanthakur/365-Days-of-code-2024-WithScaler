// https : // www.interviewbit.com/problems/zigzag-string/

#include <bits/stdc++.h>
using namespace std;

string convert(string s, int n)
{
    if (n == 1 || s.length() <= n)
    {
        return s;
    }

    vector<string> str(n, "");

    int i = 0;
    while (i < s.size())
    {
        int j = 0;
        while (j < n && i < s.size())
        {
            str[j] += s[i++];
            j++;
        }

        j -= 2;
        while (j > 0 && i < s.size())
        {
            str[j] += s[i++];
            j--;
        }
    }

    string res = "";
    for (int i = 0; i < n; i++)
    {
        res += str[i];
    }
    return res;
}