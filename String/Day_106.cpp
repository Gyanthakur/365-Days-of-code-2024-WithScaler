// https://www.interviewbit.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

string order = "IVXLCDM";

unordered_map<char, int> values;

int romanToInt(string A)
{

    values['I'] = 1;

    values['V'] = 5;

    values['X'] = 10;

    values['L'] = 50;

    values['C'] = 100;

    values['D'] = 500;

    values['M'] = 1000;

    int n = A.size();

    int ans = 0;

    int i = 0;

    while (i < n - 1)
    {

        size_t indexCurr = order.find(A[i]);

        size_t indexNext = order.find(A[i + 1]);

        if (indexCurr < indexNext)
        {

            ans += values[A[i + 1]];

            ans -= values[A[i]];

            i += 2;
        }
        else
        {

            ans += values[A[i]];

            i++;
        }
    }

    if (i <= n - 1)
    {

        ans += values[A[i]];
    }

    return ans;
}