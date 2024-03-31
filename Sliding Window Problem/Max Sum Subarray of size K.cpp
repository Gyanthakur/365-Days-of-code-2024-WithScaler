// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        long ans = 0,sum=0;
        int i=0,j=0;
        while(j<n)
        {
            sum+=arr[j];
            if(j-i+1 == k)
            {
                ans = max(ans,sum);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};
