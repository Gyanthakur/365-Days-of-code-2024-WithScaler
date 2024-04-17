// https://www.interviewbit.com/problems/multiply-strings/

#include <bits/stdc++.h>
using namespace std;
string multiply(string A, string B)
{
    int n = A.length(), m = B.length();
    string res(n + m, '0');
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int num = (A[i] - '0') * (B[j] - '0') + res[i + j + 1] - '0';
            res[i + j + 1] = num % 10 + '0';
            res[i + j] += num / 10;
        }
    }
    for (int i = 0; i < res.length(); i++)
        if (res[i] != '0')
            return res.substr(i);
    return "0";
}
