// https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

#include <bits/stdc++.h>
using namespace std;

int numTrees(int A)
{

    int dp[A + 1] = {0};

    dp[0] = 1;

    dp[1] = 1;

    dp[2] = 2;

    for (int i = 3; i <= A; i++)

    {

        for (int j = 0; j <= i - 1; j++)

        {

            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[A];
}
