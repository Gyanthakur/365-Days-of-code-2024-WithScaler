/* https://www.interviewbit.com/problems/palindrome-integer/ */


#include<bits/stdc++.h>
using namespace std;
int isPalindrome(int A) {
    if(A<0)
    {
        return 0;
    }
    string s = to_string(A);
    string g = s;
    reverse(g.begin(),g.end());
    if(g==s)
    {
        return 1;
    }
    return 0;

}