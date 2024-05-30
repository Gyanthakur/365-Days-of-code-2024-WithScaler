
// https : // www.interviewbit.com/problems/word-break/

#include <bits/stdc++.h>
        using namespace std;

bool contains(string A, vector<string> &B)
{
    for (int i = 0; i < B.size(); i++)
    {
        if (A.compare(B[i]) == 0)
            return true;
    }
    return false;
}

bool solve(string A, vector<string> &B, int indx, vector<int> &dp)
{
    if (indx == A.length())
        return true;
    if (dp[indx] != -1)
        return dp[indx];

    for (int i = indx; i < A.length(); i++)
    {
        if (contains(A.substr(indx, i - indx + 1), B) && solve(A, B, i + 1, dp))
            return dp[indx] = true;
    }
    return dp[indx] = false;
}

int wordBreak(string A, vector<string> &B)
{
    int n = A.size();
    vector<int> dp(n + 1, -1);
    return solve(A, B, 0, dp);
}