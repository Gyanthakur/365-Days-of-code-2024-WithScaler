/* https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/ */

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* inordertoBST(const vector<int>&arr, int s,int e)
{
    if(s>e)return NULL;
    int mid = s+(e-s)/2;
    TreeNode * root = new TreeNode(arr[mid]);
    root->left = inordertoBST(arr,s,mid-1);
    root->right = inordertoBST(arr,mid+1,e);
    return root;
}
TreeNode* sortedArrayToBST(const vector<int> &A) {
    
    int n = A.size();
    return inordertoBST(A,0,n-1);
}
