// https://www.interviewbit.com/problems/atoi/

#include <bits/stdc++.h>
using namespace std;
int atoi(const string s)
{
    int n = s.size();

    string temp = "";

    int i = 0;

    while (i < n && s[i] == ' ')
    {
        i++;
    }

    if (s[i] == '-' || s[i] == '+')
    {
        temp += s[i];
        i++;
    }

    while (i < n && s[i] == '0')
    {
        i++;
    }

    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        temp += s[i];
        i++;
    }

    bool neg = false;

    if (temp.empty() || temp == "+" || temp == "-")
    {
        return 0;
        // containing no integer value
        // input -> "  +-123" answer should be 0.
    }

    if (!temp.empty() && temp[0] == '-')
    {
        neg = true;
    }

    if (neg && temp.size() >= 13)
    {
        return INT_MIN;
        // overflowing to the INT_MIN extra 2 size for having negative symbol
    }

    if (!neg && temp.size() >= 13)
    {
        return INT_MAX;
        // overflowing to the INT_MAX;
    }

    long long val = stoll(temp);

    if (val > INT_MAX)
    {
        return INT_MAX;
    }

    if (val < INT_MIN)
    {
        return INT_MIN;
    }

    return val;
}
