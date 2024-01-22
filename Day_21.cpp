/* https://www.interviewbit.com/problems/reverse-integer/ */


#include<bits/stdc++.h>
using namespace std;
int reverse(int A) {
    int sign=1;
   
    if(A<0)
    {
        A=-A;
        sign=-1;
    }
    string s=to_string(A);
    int n=s.size();
    long p=0;
    for(int i=n-1;i>=0;i--)
    {
        p=p*10;
        p=p+s[i]-'0';
        if(p>INT_MAX)
        {
            return 0;
        }
    }
    if(p>INT_MAX)
    {
        return 0;
    }
    return sign*p;
}
