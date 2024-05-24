

#include <bits/stdc++.h>
using namespace std;

int rec(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    if (row >= m || col >= n)
    {
        return INT_MIN;
    }

    int ans = 0;

    if (row == m - 1 && col == n - 1)
    {
        return min(0, ans + A[row][col]);
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    ans = min(0, A[row][col] + max(rec(row + 1, col, dp, A), rec(row, col + 1, dp, A)));
    return dp[row][col] = ans;
}
int calculateMinimumHP(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int ans = rec(0, 0, dp, A);
    return abs(ans) + 1;
}
