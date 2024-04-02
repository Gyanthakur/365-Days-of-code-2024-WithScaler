// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, vector<int> &b)
{
    vector<int> tmp;
    int m = a.size(), n = b.size();
    int i = 0, j = 0;
    while (i < m || j < n)
    {
        if (i < m && a[i] <= b[j])
        {
            tmp.push_back(a[i++]);
        }
        else
        {
            tmp.push_back(b[j++]);
        }
    }
    a = tmp;
}