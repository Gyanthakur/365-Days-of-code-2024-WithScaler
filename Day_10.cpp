/* https://www.interviewbit.com/problems/ways-to-decode/ */

#include<bits/stdc++.h>
using namespace std;
int numDecodings(string A) {
    int n = A.size();
    vector<long long> dp(n+1, 0); dp[0]=1;
    if(A[0]!='0') dp[1]=1;
    else return 0;
    for(int i=1;i<n;i++){
        if(A[i]!='0') dp[i+1] = dp[i];
        int n = stoi(A.substr(i-1, 2));
        if(n>=10 && n<=26) dp[i+1]+=dp[i-1];
        dp[i+1]%=1000000007;
        if(A[i]=='0' && (n>26||n<10)) {
            return 0;
        }
    }
    return dp[n];
}
