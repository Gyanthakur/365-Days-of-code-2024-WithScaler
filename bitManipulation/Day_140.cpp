// https://www.interviewbit.com/problems/swap-bits/

#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c)
{

    b = b - 1;

    c = c - 1;

    int val1 = (a >> b) & 1;

    int val2 = (a >> c) & 1;

    if (val1 == val2)
    {

        return a;
    }

    if (val1 == 0 && val2 == 1)
    {

        a = a | (1 << b);

        a = a ^ (1 << c);
    }

    else if (val1 == 1 && val2 == 0)
    {

        a = a ^ (1 << b);

        a = a | (1 << c);
    }

    return a;
}
