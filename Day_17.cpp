/* https://www.interviewbit.com/problems/set-matrix-zeros/ */

#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int> > &a) {

    int m = a.size();
    int n = a[0].size();
   
    bool flag = false;
   
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0){
                a[i][0] = 0;
                if(j != 0){
                    a[0][j] = 0;
                } else {
                    flag = true;
                }
            }
        }
    }
   
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;
        }
    }
   
    if(a[0][0] == 0){
        for(int i = 0; i < n; i++){
            a[0][i] = 0;
        }
    }
   
    if(flag){
        for(int i = 0; i < m; i++){
            a[i][0] = 0;
        }
    }
}