/* https://www.interviewbit.com/problems/all-factors/ */

#include <bits/stdc++.h>
using namespace std;
vector<int> allFactors(int A) {
    vector<int>ans;
    for(int i=1;i*i<=A;i++)
    {
        if(A%i == 0)
        {
            ans.push_back(i);
          if (i != sqrt(A)) {
                ans.push_back(A / i);
          }
        }
    }
    sort(begin(ans),end(ans));
    return ans;
}