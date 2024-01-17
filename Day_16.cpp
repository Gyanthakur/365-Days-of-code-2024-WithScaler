/* https://www.interviewbit.com/problems/max-sum-contiguous-subarray/ */

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &a) {
    int ans = 0;
    int n = a.size();
    int maxi = a[0];
    for(int i=0;i<n;i++)
    {  
        ans+=a[i];
        maxi = max(maxi,ans);
        if(ans<0)
            ans=0;
        }
    return maxi;
}
