// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k)
{
    vector<long long> ans;
    queue<long long> q;
    int i = 0, j = 0;
    while (j < n)
    {
        if (a[j] < 0)
        {
            q.push(a[j]);
        }
        if (j - i + 1 == k)
        {
            if (q.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
            }
            if (a[i] == q.front())
            {
                q.pop();
            }
            i++;
        }
        j++;
    }
    return ans;
}
