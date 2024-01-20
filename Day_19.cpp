/* https://www.interviewbit.com/problems/spiral-order-matrix-ii/ */



#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > generateMatrix(int a) {
    vector<vector<int>>ans(a,vector<int> (a,0));
    int n = a;
    int m = a;
    int k = 1;
    int stRow = 0,stCol=0,endRow=a-1,endCol=a-1;
    while(k<=n*n)
    {
        for(int i=stCol;i<=endCol;i++)
        {
            ans[stRow][i]=k++;
        }
        stRow++;
        for(int i=stRow;i<=endRow;i++)
        {
            ans[i][endCol]=k++;
        }
        endCol--;
        if(stRow<=endRow)
        {
            for(int i=endCol;i>=stCol;i--)
            {
                ans[endRow][i]=k++;
            }
            endRow--;
        }
        if(stCol<=endCol)
        {
            for(int i=endRow;i>=stRow;i--)
            {
                ans[i][stCol]=k++;
            };
            stCol++;
        }
        
    }
    return ans;
}
