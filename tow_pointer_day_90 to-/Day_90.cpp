// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(const vector<int> &a, const vector<int> &b)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            i++;
            continue;
        }
        if (b[j] < a[i])
        {
            j++;
            continue;
        }
    }
    return ans;
}