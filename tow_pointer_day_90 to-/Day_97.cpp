// https : // www.interviewbit.com/problems/container-with-most-water/
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &A)
{
    int n = A.size();
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        int h = min(A[i], A[j]);
        int b = (j - i);
        int area = (h * b);
        ans = max(ans, area);
        if (A[i] <= A[j])
            i++;
        else
            j--;
    }
    return ans;
}