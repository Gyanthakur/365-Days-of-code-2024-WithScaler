// https://www.interviewbit.com/problems/pascal-triangle/



#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > solve(int A) {
    vector<vector<int>>ans;
    for(int i=0;i<A;i++)
    {
        vector<int>temp;
        int curr = 1;
        for(int j=1;j<=i;j++)
        {
            temp.push_back(curr);
            curr=curr*(i-j+1)/j;
        }
        temp.push_back(curr);
        ans.push_back(temp);
    }
    return ans;
}
