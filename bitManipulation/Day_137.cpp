// https://www.interviewbit.com/problems/bitwise-and-sum/



#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
vector<int> v;
int f(int sum)
{
    int l = 0, r = int(v.size()) - 1;
    int result = 0;
    while (l < r)
    {
        if (v[l] + v[r] >= sum)
        {
            result += (r - l);
            if (result >= mod)
                result -= mod;
            r--;
        }
        else
            l++;
    }
    return result;
}
int solve(vector<int> &A)
{
    int n = A.size();
    int ans = 0;
    for (int i = 0; i < 30; i++)
    {
        v.clear();
        for (int j : A)
        {
            if (j & (1 << i))
                v.push_back(j % (1 << i));
        }
        sort(v.begin(), v.end());
        ans = (ans + (1 << i) * 1ll * f(1 << i)) % mod;
    }
    return ans;
}