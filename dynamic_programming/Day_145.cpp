// https://www.interviewbit.com/problems/scramble-string/


#include <bits/stdc++.h>
using namespace std;

bool f(const string A, const string B, int la, int ra, int lb, int rb){
    if(la==ra && lb==rb){
        if(A[la]==B[lb]) return true;
        else return false;
    }
    bool ans=false;
    for(int i=la; i<ra; i++){
        bool temp;
        int length = i-la+1 ;
        string a = A.substr(la,length);
        string b1 = B.substr(lb,length);
        string b2 = B.substr(rb-length+1,length);
       
        sort(a.begin(),a.end());
        sort(b1.begin(),b1.end());
        sort(b2.begin(),b2.end());
       
        if(a==b1){
           temp = f(A,B,la,i,lb,lb+length-1)&f(A,B,i+1,ra,lb+length,rb);
        }
        else if(a==b2){
           temp = f(A,B,la,i,rb-length+1,rb)&f(A,B,i+1,ra,lb,rb-length);
        }
        else{
            temp=false;
        }
       
        ans=ans|temp;
    }
    return ans;
}

int isScramble(const string A, const string B) {
    int n=A.length();
    int m=B.length();
    if(n!=m) return false;
    return f(A,B,0,n-1,0,m-1);
}
