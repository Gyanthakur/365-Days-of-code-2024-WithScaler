/*  https://www.interviewbit.com/problems/unique-paths-in-a-grid/ */

#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int> > &A)
{
    if(A[0][0]==1) return 0;
    if(i==0&&j==0)
    {
        return 1;
    }
    else if(i<0||j<0) return 0;
    if(A[i][j]==1) return 0;
   return f(i,j-1,A)+f(i-1,j,A);
       
}
int uniquePathsWithObstacles(vector<vector<int> > &A) {
    return f(A.size()-1,A[0].size()-1,A);
}