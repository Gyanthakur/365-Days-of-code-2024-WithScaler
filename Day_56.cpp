// https://www.interviewbit.com/problems/identical-binary-trees/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



int isSameTree(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL)return 1;
    if(root1 == NULL && root2 != NULL)return 0;
    if(root1 != NULL && root2 == NULL) return 0;
    if(root1->val == root2 ->val)
    {
        bool left = isSameTree(root1->left, root2->left);
        bool right = isSameTree(root1->right, root2->right);
        return left && right;
    }
    return 0;
    
}