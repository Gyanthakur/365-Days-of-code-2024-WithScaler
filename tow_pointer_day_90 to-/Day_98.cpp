// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &A)
{
    if (A.size() <= 2)
        return A.size();
    int l = 0, h = 1;
    while (h < A.size())
    {
        if (A[l] != A[h])
        {
            A[++l] = A[h];
            h++;
            continue;
        }
        while (A[l] == A[h] && h < A.size())
        {
            h++;
        }
        if (h == A.size())
        {
            A[l + 1] = A[l];
            return l + 2;
        }
        else
        {
            A[l + 1] = A[l];
            A[l + 2] = A[h];
            l = l + 2;
            h++;
        }
    }
    return l + 1;
}