// https://www.interviewbit.com/problems/rain-water-trapped/


#include <bits/stdc++.h>
using namespace std;
int trap(const vector<int> &A)
{
    int total = 0;
    if (A.size() < 3)
    {
        return 0;
    }
    vector<int> left(A.size(), 0), right(A.size(), 0);
    left[0] = A[0];
    right[A.size() - 1] = A[A.size() - 1];
    for (int i = 1; i < A.size(); i++)
    {
        // towards left, make an array with just increasing order
        left[i] = max(left[i - 1], A[i]);                                        
        // towards right, make an array with just increasing order
        right[A.size() - i - 1] = max(right[A.size() - i], A[A.size() - 1 - i]); 
    }
    for (int i = 0; i < A.size(); i++)
    {
        total += min(left[i], right[i]) - A[i]; // as we already compared with A[i] therefore its always positive
    }
    return total;
}
