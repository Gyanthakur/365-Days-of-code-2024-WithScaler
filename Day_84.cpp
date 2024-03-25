// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
   
    // finding the index of previous smaller elements
    vector<int> prevsmaller(n, -1);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()) s.push(i);
        else {
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(!s.empty()) prevsmaller[i] = s.top();
            s.push(i);
        }
    }
   
    // finding the index of next smaller elements
    vector<int> nextsmaller(n, n);
    stack<int> t;
    for(int i=n-1;i>=0;i--){
        if(t.empty()) t.push(i);
        else {
            while(!t.empty() && heights[t.top()]>=heights[i]) t.pop();
            if(!t.empty()) nextsmaller[i] = t.top();
            t.push(i);
        }
    }
   
    // calculate the answer
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, heights[i]*(nextsmaller[i]-prevsmaller[i]-1));
    return ans;
}