// https://www.interviewbit.com/problems/word-break-ii/



#include <bits/stdc++.h>
using namespace std;
void findans(int i, int n, string A, vector<string> &B, vector<string> &ans, string &s)
{
    if (i == n)
    {
        ans.push_back(s);
        return;
    }

    for (int j = 0; j < B.size(); ++j)
    {
        string str = B[j];
        int len = str.length();

        if (i + len <= n && A.substr(i, len) == str)
        {
            string substring = s + str;
            if (i + len < n)
            {
                substring += " ";
            }
            findans(i + len, n, A, B, ans, substring);
        }
    }
}

vector<string> wordBreak(string A, vector<string> &B)
{
    vector<string> ans;
    string s = "";
    findans(0, A.size(), A, B, ans, s);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}
