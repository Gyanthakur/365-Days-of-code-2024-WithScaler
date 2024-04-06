// https://www.interviewbit.com/problems/array-3-pointers/

#include <bits/stdc++.h>
using namespace std;

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int a = A.size(), b = B.size(), c = C.size();
    int ans = INT_MAX;

    int i = a - 1, j = b - 1, k = c - 1;

    while (i >= 0 && j >= 0 && k >= 0)
    {
        int maxE = max({A[i], B[j], C[k]});
        int minE = min({A[i], B[j], C[k]});

        if (A[i] == maxE)
            i--;
        else if (B[j] == maxE)
            j--;
        else
            k--;

        ans = min(ans, maxE - minE);
    }

    return ans;
}