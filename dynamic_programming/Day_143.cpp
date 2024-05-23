// https://www.interviewbit.com/problems/regular-expression-match/

#include <bits/stdc++.h>
using namespace std;

int isMatch(const string A, const string B)
{

    int n = A.length(), m = B.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        dp[i][0] = false;

    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int ii = 1; ii <= j; ii++)
        {
            if (B[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1] || B[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (B[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}