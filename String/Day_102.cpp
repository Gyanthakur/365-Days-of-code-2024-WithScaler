// https://www.interviewbit.com/problems/count-and-say/



#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n)
{

    if (n == 1)

        return "1";

    else if (n == 2)

        return "11";

    vector<string> dp(n + 1, "");

    dp[1] = "1";

    dp[2] = "11";

    for (int i = 3; i <= n; i++)
    {

        string s = dp[i - 1];

        string res = "";

        int cnt = 1;

        for (int j = 1; j < s.size(); j++)
        {

            if (s[j] == s[j - 1])

                cnt++;

            else
            {

                res += to_string(cnt) + s[j - 1];

                cnt = 1;
            }
        }

        res += to_string(cnt) + s[s.size() - 1];

        dp[i] = res;
    }

    return dp[n];
}
