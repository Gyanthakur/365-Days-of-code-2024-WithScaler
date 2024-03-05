// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/


#include <bits/stdc++.h>
using namespace std;
int maxProfit(const vector<int> &prices) {
    int n = prices.size();
    if(n == 0) return 0;
   
    vector<int> maxPrices(n, 0);
    maxPrices[n-1] = prices[n-1];
   
    for(int i = n-2; i >= 0; i--){
        maxPrices[i] = max(maxPrices[i+1], prices[i]);
    }
   
    int maxProfit = 0;
    for(int i = 0; i < n; i++){
        maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
    }
   
    return maxProfit;
}