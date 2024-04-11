// https://www.interviewbit.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &a)
{
    int n = a.size();
    int minLen = INT_MAX;
    for (int i = 0; i < n; i++)
        if (minLen > a[i].length())
            minLen = a[i].length();

    string ans = "";
    for (int i = 0; i < minLen; i++)
    {
        char c = a[0][i];
        for (int j = 0; j < n; j++)
            if (a[j][i] != c)
                return ans;
        ans += c;
    }
    return ans;
}