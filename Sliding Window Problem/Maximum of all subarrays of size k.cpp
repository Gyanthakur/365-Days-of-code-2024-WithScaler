// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>ans;
        list<int>l;
        int i=0,j=0;
        while(j<n)
        {
            while(!l.empty() && arr[j] > l.back())
            {
                l.pop_back();
            }
            l.push_back(arr[j]);
            if(j-i+1 == k)
            {
                ans.push_back(l.front());
                if(arr[i] == l.front())
                {
                    l.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};