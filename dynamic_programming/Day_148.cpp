

// https://www.interviewbit.com/problems/edit-distance/


#include<bits/stdc++.h>
using namespace std;

int f(int i ,int j , string &A, string &B,vector<vector<int>> &dp)

{

    if(i==A.size())    // The remaining letters of B need to be inserted by these many operations

    return B.size()-j; 

    

    if(j==B.size())    // The remaining letters of A need to be deleted by these many operations

    return A.size()-i;

    

    if(dp[i][j]!=-1)

    return dp[i][j];

    

    if(A[i]==B[j])

    return dp[i][j]=0+f(i+1,j+1,A,B,dp); //If the letters match then no operation needed.

    else

    return dp[i][j]=1+min(f(i+1,j,A,B,dp) , min(f(i,j+1,A,B,dp) , f(i+1, j+1, A , B,dp)));

    // If letters dont match one operation would be needed. Which it would be is decided by the minimum criteria

    // f(i+1,j,A,B) goes for delete the ith element

    // f(i+1,j+1,A,B) goes for replace the ith element

    // f(i,j+1,A,B) goes for insert at the ith pos.

    

}



int minDistance(string A, string B) {

    int n=A.size();

    int m=B.size();

    

    vector<vector<int>> dp(n,vector<int>(m,-1));

    return f(0,0,A,B,dp);

}

