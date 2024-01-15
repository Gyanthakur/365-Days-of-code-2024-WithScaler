/* https://www.interviewbit.com/problems/rotate-matrix/ */

#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int> > &matrix) {
   reverse(matrix.begin(), matrix.end());
    for(int i = 0; i<matrix.size(); i++) {
        for(int j = i + 1; j<matrix[i].size(); j++) 
            swap(matrix[i][j], matrix[j][i]);
    }
}