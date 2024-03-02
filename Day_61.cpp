// https://www.interviewbit.com/problems/path-sum/






#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 bool flag = 0;
 void solve(TreeNode* root, int sum)
 {
     if(root == NULL )return;
     if(sum - root->val == 0 && root->left == NULL && root->right == NULL)
     {
        flag = 1;
        return;
     }
     solve(root->left,sum-root->val);
     solve(root->right, sum-root->val);
 }
int hasPathSum(TreeNode* A, int B) {
    flag = 0;
    solve(A,B);
    return flag;
}