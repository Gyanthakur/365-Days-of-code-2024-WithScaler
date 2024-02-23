// https://www.interviewbit.com/problems/symmetric-binary-tree/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSameTree(TreeNode *A, TreeNode *B)
{
    if (!A || !B)
        return A == B;
    return (A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right));
}

TreeNode *invertTree(TreeNode *A)
{
    if (A == NULL)
        return A;
    TreeNode *temp = A->left;
    A->left = A->right;
    A->right = temp;
    invertTree(A->left);
    invertTree(A->right);
    return A;
}

int isSymmetric(TreeNode *A)
{
    if (A == NULL)
        return 1;
    return isSameTree(A->left, invertTree(A->right));
}