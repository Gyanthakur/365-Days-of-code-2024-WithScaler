// https://www.interviewbit.com/problems/merge-overlapping-intervals/
#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval> &a)
{

    vector<Interval> ans;
    sort(begin(a), end(a), [](Interval &a1, Interval &a2)
         { return a1.start < a2.start; });
    ans.push_back(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        if (ans.back().end >= a[i].start)
        {
            ans.back().end = max(ans.back().end, a[i].end);
        }
        else
            ans.push_back(a[i]);
    }
    return ans;
}