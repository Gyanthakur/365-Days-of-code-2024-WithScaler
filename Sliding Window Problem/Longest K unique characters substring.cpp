// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int n = s.length(), i = 0, j = 0, ans = -1;
        unordered_map<char, int> m;
        while (j < n)
        {
            m[s[j]]++;
            if (m.size() == k)
                ans = max(ans, j - i + 1);
            if (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};