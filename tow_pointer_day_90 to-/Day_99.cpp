https://www.interviewbit.com/problems/diffk/

#include <bits/stdc++.h>
using namespace std;
int diffPossible(vector<int> &a, int b) {
    int n = a.size();
    int i=0,j=0;
    while(j<n)
    {
        if(a[j]-a[i]==b && i!=j)
        {
            return 1;
        }
        else if(a[j]-a[i] > b)
        i++;
        else 
        j++;
    }
    return 0;
}
