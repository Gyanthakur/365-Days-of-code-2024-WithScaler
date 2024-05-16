// https://www.interviewbit.com/problems/maximize-matrix-xor/

#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &A)
{
    int n = A.size(), m = A[0].size(), x = 0;
    int r[n] = {0}, c[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x ^= A[i][j];
            r[i] ^= (A[i][j] ^ (A[i][j] - 1));
            c[j] ^= (A[i][j] ^ (A[i][j] - 1));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, x ^ r[i]);
    for (int i = 0; i < m; i++)
        ans = max(ans, x ^ c[i]);
    return ans;
}