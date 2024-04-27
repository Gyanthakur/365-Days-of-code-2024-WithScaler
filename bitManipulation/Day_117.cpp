
// https://www.interviewbit.com/problems/reverse-bits/

#include <bits/stdc++.h>
using namespace std;


unsigned int reverse(unsigned int A) {
    
    unsigned int ans = 0;
    if(A == 0) return A;
    
    int j = 0;
    for(int i = 31; i>= 0; i--)
    {
        int temp = ((A>>i) & 1);
        ans += (temp << j);
        j++;
    }
    return ans;
    

}
