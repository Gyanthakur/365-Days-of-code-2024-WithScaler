// https://www.interviewbit.com/problems/longest-valid-parentheses/


#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string A) {
    int n= A.size();
    int i=0;
    stack<pair<char, int>> st;
    int maxl=0;
    while(i<n){
        if(!st.empty() && A[i]==')' && st.top().first == '('){
            st.pop();
            if(!st.empty())maxl = max(maxl, i-st.top().second);
            else maxl= max(maxl, i+1);
        }else{
            st.push({A[i], i});
        }
        i++;
    }
    return maxl;
}