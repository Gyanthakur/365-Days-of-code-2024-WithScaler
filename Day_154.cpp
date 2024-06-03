

#include <bits/stdc++.h>
using namespace std;
string findDigitsInBinary(int N) {
    if(N==0)return "0";
 
    string ans ="";
   
    while(N){
        ans.push_back('0'+ N%2);
        N/=2;
    }
   
    reverse(ans.begin(),ans.end());
   
    return ans;
}