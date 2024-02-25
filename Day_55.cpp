// https://www.interviewbit.com/problems/valid-binary-search-tree/



#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int isBst(TreeNode * root, int mini, int maxi)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->val > mini && root->val < maxi)
    {
        bool left = isBst(root->left, mini, root->val);
        bool right = isBst(root->right, root->val, maxi);
        if( left && right)
        return 1;
    }
    return 0;
}
int isValidBST(TreeNode* root) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    return isBst(root, mini, maxi);
}