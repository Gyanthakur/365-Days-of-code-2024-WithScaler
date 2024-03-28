// https://www.interviewbit.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int> &A)
{
    int n = A.size();
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = A[i];
    }
    next_permutation(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        A[i] = arr[i];
    }
    return A;
}
