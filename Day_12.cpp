/* https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/ */

#include<bits/stdc++.h>
using namespace std;
int maxProfit(const vector<int> &A) 
{
    int n=A.size();
    if(n==0)    
        return 0;
    vector<int>vec(n-1,0);
    int profit=0;
    for(int i=1;i<n;i++)
    {
        int x=A[i]-A[i-1];
        vec.push_back(x);  
        if(x>0)
        {
            profit=profit+x;
        }
    }
    return profit;
}
