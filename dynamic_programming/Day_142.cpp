

#include <bits/stdc++.h>
using namespace std;

int f(int index, int buy, int cap, const vector<int> &A, vector<vector<vector<int>>> &dp)

{

    if (index == A.size()) // U have exhausted the days of the transaction

        return 0;

    if (cap == 0) // U have done 2 transactions so u cant do anymore

        return 0;

    if (dp[index][buy][cap] != -1)

        return dp[index][buy][cap];

    int profit;

    // If we can allowed to buy then either we buy or we dont buy.

    if (buy)

        profit = max(-A[index] + f(index + 1, 0, cap, A, dp), 0 + f(index + 1, 1, cap, A, dp));

    else

        profit = max(+A[index] + f(index + 1, 1, cap - 1, A, dp), 0 + f(index + 1, 0, cap, A, dp));

    return dp[index][buy][cap] = profit;
}

int maxProfit(const vector<int> &A)
{

    int n = A.size();

    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

    // return f(0,1,2,A);

    vector<vector<int>> curr(2, vector<int>(3, 0));

    vector<vector<int>> after(2, vector<int>(3, 0));

    if (n == 0 || n == 1)

        return 0;

    int profit;

    for (int index = n - 1; index >= 0; index--)

    {

        for (int buy = 0; buy < 2; buy++)

        {

            for (int cap = 1; cap < 3; cap++)

            {

                // If we can allowed to buy then either we buy or we dont buy.

                if (buy)

                    profit = max(-A[index] + after[0][cap], 0 + after[1][cap]);

                else // If we are allowed to sell then either we sell or we dont.

                    profit = max(+A[index] + after[1][cap - 1], 0 + after[0][cap]);

                curr[buy][cap] = profit;
            }
        }

        after = curr;
    }

    return after[1][2];
}
