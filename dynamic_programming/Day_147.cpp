// https://www.interviewbit.com/problems/min-sum-path-in-matrix/



#include <bits/stdc++.h>
using namespace std;

int solve(int row,int column,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if (row==0 && column==0){
            return arr[0][0];
        }
        if (row<0 || column <0){
            return 10e6;
        }
        if (dp[row][column]!=-1){
            return dp[row][column];
        }
        int x=solve(row-1,column,arr,dp);
        if (x!=10e6);
        int up = arr[row][column]+x;
        int y=solve(row,column-1,arr,dp);
        if (y!=10e6);
        int left=arr[row][column]+y;
        return dp[row][column]=min(up,left);

    }
int minPathSum(vector<vector<int> > &grid) {
     int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
}