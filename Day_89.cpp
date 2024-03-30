// https://www.interviewbit.com/problems/maximum-consecutive-gap/

// ✅✅ 😀😊😎🤗😇😸🐼🦄🌟💫🌈🎉🎈🎶🍕🍉🍩🚀⚽🎸💥💫💥💫✅✅🌀🔹

#include <bits/stdc++.h>
using namespace std;
int maximumGap(const vector<int> &arr) {
    int n = arr.size();
    if(n<2)return 0;
    int ans  = -12;
    vector<int>A(n);
    for(int i=0;i<n;i++)
    A[i] = arr[i];
    sort(begin(A),end(A));
    for(int i=0;i<n-1;i++)
    {
        int  y = A[i+1]-A[i];
        ans = max(ans,y);
    }
    return ans;
}
