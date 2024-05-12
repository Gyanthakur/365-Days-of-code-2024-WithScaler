// https://www.interviewbit.com/problems/min-xor-value/

#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>

int findMinXor(std::vector<int> &A)
{
    sort(A.begin(), A.end());

    int minXor = INT_MAX;

    for (int i = 0; i < A.size() - 1; ++i)
    {
        minXor = std::min(minXor, A[i] ^ A[i + 1]);
    }

    return minXor;
}