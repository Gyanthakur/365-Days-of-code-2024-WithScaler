// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

#include<bits/stdc++.h>
using namespace std;
vector<int> getRow(int A) {
    vector<int>ans{1};
    for(int i=1;i<=A;i++)
    {
        vector<int>next_row(ans.size()+1,0);
        for(int j=0;j<ans.size();j++)
        {
            next_row[j]+=ans[j];
            next_row[j+1]+=ans[j];
        }
        ans = next_row;
    }
    return ans;
}
