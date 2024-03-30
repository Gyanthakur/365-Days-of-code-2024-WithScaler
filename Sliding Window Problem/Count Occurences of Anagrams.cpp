// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(string pat, string s)
    {
        int ans = 0;
        unordered_map<char, int> m;
        for (auto &it : pat)
            m[it]++;
        int i = 0, j = 0, k = pat.length(), n = s.length();
        int cnt = m.size();
        while (j < n)
        {
            if (m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if (m[s[j]] == 0)
                {
                    cnt--;
                }
            }
            if (j - i + 1 == k)
            {
                if (cnt == 0)
                {
                    ans++;
                }
                if (m.find(s[i]) != m.end())
                {
                    if (m[s[i]] == 0)
                    {
                        cnt++;
                    }
                    m[s[i]]++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};