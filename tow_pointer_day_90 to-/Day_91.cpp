// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A)
{
    int i = 0, j = 1;
    while (j < A.size())
    {
        if (A[i] == A[j])
        {
            j++;
        }
        else
        {
            swap(A[i + 1], A[j]);
            i++;
            j++;
        }
    }
    return i + 1;
}
