// https://www.interviewbit.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A)
{
    int ans = 0;
    for (auto it : A)
        ans ^= it;
    return ans;
}
