// https://www.interviewbit.com/problems/palindrome-string/

#include<bits/stdc++.h>
using namespace std;
int isPalindrome(string A) {
    vector<char>ch;
    for(char c: A)
    {
        if(isalnum(c))
        ch.push_back(tolower(c));
    }
    for(int i=0;i<ch.size()/2;i++)
    {
        if(ch[i]!=ch[ch.size()-1-i])
        return 0;
       
    }
    return 1;
}