
// https://www.interviewbit.com/problems/add-binary-strings/

#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B) {
    int n=A.length(), m=B.length(), carry=0;
    string ans="";
    int j=m-1;
    int i=n-1;                          
    while(i>=0 && j>=0){
        int k = (carry+(A[i]-'0')+(B[j]-'0'))%2;
        ans = to_string(k) + ans;
        carry = (carry+(A[i]-'0')+(B[j]-'0'))/2;
        i--;
        j--;
    }
    while(i>=0){
        int k = (carry + (A[i]-'0'))%2;
        ans = to_string(k) + ans;
        carry = (carry + (A[i]-'0')) /2;
        i--;
    }
    while(j>=0){
        int k = (carry + (B[j]-'0'))%2;
        ans = to_string(k) + ans;
        carry = (carry + (B[j]-'0')) /2;
        j--;
    }
    if(carry){
        ans = to_string(1) + ans;
    }
    return ans;
}
