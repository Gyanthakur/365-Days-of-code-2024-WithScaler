// https://www.interviewbit.com/problems/max-distance/

#include <bits/stdc++.h>
using namespace std;
int maximumGap(const vector<int> &A)
{
    int n = A.size();
    int mx = -1;
    vector<pair<int, int>> v;
    for (int i = n - 1; i >= 0; i--)
    {
        v.push_back(make_pair(A[i], i));
    }
    sort(v.begin(), v.end());
    int mn = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, v[i].second);
        ans = max(ans, v[i].second - mn);
    }
    return ans;
}