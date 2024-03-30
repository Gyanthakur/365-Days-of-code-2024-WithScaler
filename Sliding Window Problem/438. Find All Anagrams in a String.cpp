// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        unordered_map<char, int> m;
        for (auto &it : p)
            m[it]++;
        int cnt = m.size();
        int n = s.length(), i = 0, j = 0;
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
            if (j - i + 1 == p.length())
            {
                if (cnt == 0)
                {
                    ans.push_back(i);
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