// https://www.interviewbit.com/problems/n3-repeat-number/

#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    int ans, flag = 0;
    for (int i = 0; i < 23; i++)
    {

        int index = rand() % n;
        int elem = A[index];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == elem)
                count++;
        }

        if (count > n / 3)
        {
            flag = 1;
            ans = elem;
        }

        if (flag == 1)
            break;
    }

    if (flag == 1)
        return ans;
    else
        return -1;
}