

#include <bits/stdc++.h>
using namespace std;

int solve(int A)
{
    return pow(2, floor(log2(A)) + 1) - A - 1;
}