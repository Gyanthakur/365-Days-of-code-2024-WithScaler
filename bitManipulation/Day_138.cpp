
// https://www.interviewbit.com/problems/or-equal-xor/
#include <bits/stdc++.h>
using namespace std;

int expo(int a, int b, int mod)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return ans;
}
int solve(int A)
{
    return expo(3, A, 1e9 + 7);
}