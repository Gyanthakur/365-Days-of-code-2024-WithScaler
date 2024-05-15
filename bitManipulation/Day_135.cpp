// https://www.interviewbit.com/problems/xor-ing-the-subarrays/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    if (A.size() % 2 == 0)
        return 0; // Any even length array will always result in 0

    int x = A[0]; // and in odd size array only XOR of odd elements will contribute to result

    for (int i = 2; i < A.size(); i += 2)
    {
        x = x ^ A[i]; // calculating XOR of odd elements
    }
    return x;
}
