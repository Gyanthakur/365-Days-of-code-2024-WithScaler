// https://www.interviewbit.com/problems/divide-integers/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll helper(ll a,ll b)
{
    if(a<0) a*=-1;
    if(b<0) b*=-1;
    if(b==1) return a;
    if(a<b) return 0;
    ll x=1;
    while((b<<x)<=a) x++;
    x--;
    return (1<<x)+helper(a-(b<<x),b);
}

int divide(int A, int B) {
    bool flag=true;
    if(A<0 && B<0) flag=true;
    else if(A<0) flag=false;
    else if(B<0) flag=false;
    ll ans=helper(ll(A),ll(B));
    if(!flag) ans*=-1;
    if(ans>INT_MAX) return INT_MAX;
    return int(ans);
}
