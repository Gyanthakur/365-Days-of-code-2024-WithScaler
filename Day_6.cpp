/* https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/discussion/p/too-easy-to-understand-c/313789/383/ */

/*

Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0
    ]

Output : 4

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

*/

#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
                dp[i + 1][j + 1] = 0;
            else
            {
                dp[i + 1][j + 1] = 1 + dp[i][j + 1];
            }
        }
    }
    int area = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int wid = dp[i][j];
            for (int k = j; k <= m; k++)
            {
                wid = min(wid, dp[i][k]);
                int tar;
                tar = (k - j + 1) * wid;
                area = max(area, tar);
            }
        }
    }
    return area;
}