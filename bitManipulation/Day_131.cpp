
// https://www.interviewbit.com/problems/different-bits-sum-pairwise/

#include <bits/stdc++.h>
using namespace std;


int cntBits(vector<int> &A)
{
    int MOD = 1000000007;
    long sum = 0;
    int finalSum = 0;

    long n = A.size();

    for (long i = 0; i < 32; i++)
    {

        long zeroCount = 0;
        for (int ele : A)
        {

            int checkBit = (1 << i) & ele;

            if (checkBit == 0)
            {
                zeroCount++;
            }
        }

        sum = (sum % MOD + (2l * zeroCount * (n - zeroCount)) % MOD) % MOD;
    }

    finalSum = (int)(sum % MOD);
    return finalSum;
}
