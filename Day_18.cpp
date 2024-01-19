/*https://www.interviewbit.com/problems/spiral-order-matrix-i/*/



#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(const vector<vector<int> > &a) {
    vector<int>ans;
    int n = a.size();
    int m = a[0].size();
    int stRow = 0,stCol=0,endRow=n-1,endCol=m-1;
    while(stRow <= endRow && stCol <= endCol)
    {
        for(int i=stCol;i<=endCol;i++)
        {
            ans.push_back(a[stRow][i]);
        }
        stRow++;
        for(int i=stRow;i<=endRow;i++)
        {
            ans.push_back(a[i][endCol]);
        }
        endCol--;
        if(stRow<=endRow)
        {
            for(int i=endCol;i>=stCol;i--)
            {
                ans.push_back(a[endRow][i]);
            }
            endRow--;
        }
        if(stCol<=endCol)
        {
            for(int i=endRow;i>=stRow;i--)
            {
                ans.push_back(a[i][stCol]);
            };
            stCol++;
        }
        
    }
    return ans;
}
