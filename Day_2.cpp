/* https://www.interviewbit.com/problems/majority-element/ */
/*
Problem Description
 
 

Given an array of size N, find the majority element. The majority element is the element that appears more than floor(N/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.



Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 109


Input Format
The first argument is an integer array A.


Output Format
Return the majority element.


Example Input
A = [2, 1, 2]


Example Output
2


Example Explanation
2 occurs 2 times which is greater than 3/2.


*/

#include<bits/stdc++.h>
using namespace std;


int majorityElement(vector<int>& nums) {
   int n=nums.size();
   int element = nums[0];
   int cnt = 0;
   for(int i=0;i<n;i++)
   {
    if(cnt = 0)
        element = nums[i];
    if(element = nums[i])
        cnt+=1;
    else
        cnt-=1;
   }
    return element;
}
int main()
{
    int n = 3;
    vector<int>a = {2,1,2};
    cout<<majorityElement(a);
}