/* https://x.com/gps_96169/status/1754900440792129710?s=20 */


#include <bits/stdc++.h>
using namespace std;
int findCount(const vector<int> &A, int B)
{
    int n = A.size();
    int i, l = 0, h = n - 1, ans = 0;

    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (A[m] > B)
            h = m - 1;
        else if (A[m] < B)
            l = m + 1;
        else
        {
            i = m;
            break;
        }
    }
    int x = i + 1;
    while (A[i] == B && i >= 0)
    {
        ans++;
        i--;
    }
    while (A[x] == B && x < n)
    {
        ans++;
        x++;
    }

    return ans;
}
