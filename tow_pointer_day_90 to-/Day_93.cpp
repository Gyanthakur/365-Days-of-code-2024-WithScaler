// https://www.interviewbit.com/problems/sort-by-color/

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &a)
{

    int slow = 0, mid = 0, high = a.size() - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[slow], a[mid]);
            slow++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[high], a[mid]);
            high--;
        }
    }
}