// https://www.interviewbit.com/problems/search-in-bitonic-array/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int B)
{
    int n = arr.size();
    int low = 1, high = n - 2, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            ans = mid;
            break;
        }
        else if (arr[mid] > arr[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    low = 0, high = ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == B)
            return mid;
        else if (arr[mid] > B)
            high = mid - 1;
        else
            low = mid + 1;
    }
    low = ans, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == B)
            return mid;
        else if (arr[mid] > B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}