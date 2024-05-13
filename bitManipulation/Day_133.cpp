// https://www.interviewbit.com/problems/trailing-zeroes/


#include <bits/stdc++.h>
using namespace std;

int solve(int a) {
    int ans = 0;
    while((a&1) == 0 && a>0)
    {
        ans++;
        a>>=1;
    }
    return ans;
}
