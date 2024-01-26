/* https://www.interviewbit.com/problems/excel-column-number/ */

#include<bits/stdc++.h>
using namespace std;
int titleToNumber(string a) {
    int n = a.size();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans = ans*26+(a[i]-'A'+1);
    }
    return ans;
    
}
