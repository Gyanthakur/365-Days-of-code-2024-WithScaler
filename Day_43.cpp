// https://www.interviewbit.com/problems/next-greater-number-bst/





#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 
 void inorder(TreeNode * root, vector<int>&in)
 {
     if(root==NULL)return ;
     inorder(root->left,in);
     in.push_back(root->val);
     inorder(root->right,in);
 }
TreeNode* getSuccessor(TreeNode* A, int B) {
    /*
    TreeNode * successor = NULL;
    while(A!=NULL)
    {
        if(B>=A->val)
        {
            A=A->right;
        }
        else
        {
            successor = A;
            A=A->left;
        }
    }
    return successor;
    */
    vector<int>ino;
    inorder(A,ino);
    int x=0;
    for(int i=0;i<ino.size();i++)
    {
        if(ino[i]==B)
        x=i;
    }
    TreeNode* z= new TreeNode(ino[x+1]);
    return z;
    
    
}
