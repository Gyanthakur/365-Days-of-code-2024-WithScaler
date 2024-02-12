// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

#include <bits/stdc++.h>
using namespace std;
vector<int> getRow(int A)
{
    /*
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

    */

    // another method

    /*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1     k==4--> 1 , 1*(4/1)==4  --> 4*(3/2) == 6 --> 6*(2/3) == 4, --> 1 formula == arr[i-1]*(k+1-i)/i
1 5 10 10 5 1


    */

    vector<int> ans{1};
    if (A == 0)
        return ans;
    for(int i=1;i<A;i++)
    {
        int val = ans[i-1]*(A+1-i)/i;
        ans.push_back(val);
    }
    ans.push_back(1);
    return ans;
}
