
// https://www.interviewbit.com/problems/palindrome-partitioning-ii/



#include <bits/stdc++.h>
using namespace std;
bool ispal(string s)
{

    int n = s.size();

    for (int i = 0; i < n / 2; i++)
    {

        if (s[i] != s[n - 1 - i])
            return false;
    }

    return true;
}

int minCut(string A)
{

    int n = A.size();

    vector<int> dp(n + 1, 10000);

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {

        string temp;

        for (int j = i + 1; j <= n; j++)
        {

            if (j)
            {

                temp += A[j - 1];

                if (ispal(temp))
                {

                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
    }

    return dp[n] - 1;
}