// https://www.interviewbit.com/problems/valid-ip-addresses/
#include <bits/stdc++.h>
using namespace std;

vector<string> restoreIpAddresses(string A)
{
    vector<string> ans;
    int n = A.size();
    for (int i = 1; i < 4 && i < n - 2; i++)
    {
        for (int j = i + 1; j < i + 4 && j < n - 1; j++)
        {
            for (int k = j + 1; k < j + 4 && k < n; k++)
            {
                string a = A.substr(0, i);
                string b = A.substr(i, j - i);
                string c = A.substr(j, k - j);
                string d = A.substr(k, n - k);
                if (a.size() >= 4 || b.size() >= 4 || c.size() >= 4 || d.size() >= 4)
                    continue;
                if (stoi(a) > 255 || stoi(b) > 255 || stoi(c) > 255 || stoi(d) > 255)
                    continue;
                if ((a[0] == '0' && a.size() > 1) || (b[0] == '0' && b.size() > 1) || (c[0] == '0' && c.size() > 1) || (d[0] == '0' && d.size() > 1))
                    continue;
                ans.push_back(a + "." + b + "." + c + "." + d);
            }
        }
    }
    return ans;
}
