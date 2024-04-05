// https://www.interviewbit.com/problems/3-sum/
#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    int closestSum = INT_MAX;
    int minDiff = INT_MAX;
   
    sort(A.begin(), A.end());
   
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;
       
        while (j < k) {
            int sum = A[i] + A[j] + A[k];
           
            if (sum == B) {
                return sum;
            } else if (sum < B) {
                if (B - sum < minDiff) {
                    minDiff = B - sum;
                    closestSum = sum;
                }
                j++;
            } else {
                if (sum - B < minDiff) {
                    minDiff = sum - B;
                    closestSum = sum;
                }
                k--;
            }
        }
    }
    return closestSum;
}