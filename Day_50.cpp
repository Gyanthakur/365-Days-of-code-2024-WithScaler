// https://www.interviewbit.com/problems/balanced-binary-tree/



#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int height(TreeNode* A){

    if(A==NULL){ return 0;}
    int lh = height(A->left);
    if(lh==-1){return -1;}
    int rh = height(A->right);
    if(rh==-1){return -1;}
    if(abs(lh-rh)>1){ return -1;}
    else{
        return max(lh,rh)+1;
    }
}

int isBalanced(TreeNode* A) {
    if(height(A)==-1){ return 0;}
    else {
        return 1;
    }
}
