// https://www.interviewbit.com/problems/longest-palindromic-substring/
#include <bits/stdc++.h>
using namespace std;
void helper(int l,int r,string &s,int &maxlen,int &left,int &right){
    while(l>=0 && r<s.size() && s[l]==s[r]){
        if(r-l+1>maxlen){
            maxlen=r-l+1;
            left=l;
            right=r;
        }
        l--;
        r++;
    }
}
string longestPalindrome(string A) {
    int maxlen=1;
    int left=0,right=0;
    for(int i=1;i<A.size();i++){
        helper(i-1,i+1,A,maxlen,left,right);
    }
    for(int i=0;i<A.size();i++){
        helper(i,i+1,A,maxlen,left,right);
    }
    return A.substr(left,right-left+1);
}