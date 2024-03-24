// https://www.interviewbit.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;
vector<int> slidingMaximum(const vector<int> &A, int B)
{
    priority_queue<pair<int, int>> p;
    int n = A.size();
    int i = 0;
    for (i = 0; i < B; i++)
    {
        p.push({A[i], i + 1});
    }
    vector<int> ans;
    ans.push_back(p.top().first);
    int x = 1;
    while (i < n)
    {
        p.push({A[i], i + 1});
        while ((p.top()).second - x <= 0)
        {
            p.pop();
        }
        ans.push_back((p.top()).first);
        i++;
        x++;
    }
    return ans;
}