/* https://www.interviewbit.com/problems/prime-numbers/ */

#include<bits/stdc++.h>
using namespace std;


vector<int>sieve(int n) {
    bool a[n+1];
 for(int i=0;i<=n;i++){
     a[i]=true;
 }
 a[0]=false;
 a[1]=false;
 
 for(int i=2;(i*i)<=n;i++){
     
     if(a[i]==true){
         for(int j=i*i;j<=n;j=j+i){
             a[j]=false;
         }
     }
     
     
 }
 vector<int> v;
 for(int i=2;i<=n;i++){
     if(a[i]==true){
         v.push_back(i);
     }
 }

    
 return v;
}
