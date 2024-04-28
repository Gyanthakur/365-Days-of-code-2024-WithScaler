// https://www.interviewbit.com/problems/number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;
int numSetBits(unsigned int A)
{
    int count = 0;
    while (A)
    {
        if ((A & 1) == 1)
        {
            count++;
        }
        A >>= 1;
    }
    return count;
}
