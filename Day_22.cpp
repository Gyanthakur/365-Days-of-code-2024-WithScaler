/* https://www.interviewbit.com/problems/add-one-to-number/discussion/ */


#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &a) {
    int n = a.size();
    a[n-1]+=1;
    for(int i=n-1;i>0;i--)
    {
        if(a[i] == 10)
        {
            a[i] = 0;
            a[i-1]+=1;
        }
    }
    if(a[0]==10)
    {
        a[0]=0;
        a.insert(a.begin(),1);
    }
    auto it=a.begin();
    while(*it==0)
        a.erase(it);
    return a;
}
