/* https://www.interviewbit.com/problems/merge-intervals/ */

#include <bits/stdc++.h>
using namespace std;
bool static cmp(Interval i1, Interval i2)
{

    return i2.start > i1.start;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{

    intervals.push_back(newInterval);

    sort(intervals.begin(), intervals.end(), cmp);

    vector<Interval> ans;

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {

        if (ans.back().end >= intervals[i].start)
        {

            ans.back().end = max(ans.back().end, intervals[i].end);
        }

        else
            ans.push_back(intervals[i]);
    }

    return ans;
}