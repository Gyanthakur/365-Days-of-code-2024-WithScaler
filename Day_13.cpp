/* https://www.interviewbit.com/problems/repeat-and-missing-number-array/ */

#include<bits/stdc++.h>
using namespace std;
vector<int>repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int B[n+1]={0};
    int a=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
        B[A[i]]++;
    }
    for(int i=0;i<=n;i++)
    {
        if(B[i]==0)
        {
            a=i;
        }
        if(B[i]==2)
        {
            b=i;
        }
    }
    return {b,a};
}