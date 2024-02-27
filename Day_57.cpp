// https://www.interviewbit.com/problems/min-depth-of-binary-tree/



#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode* root, int & ans, int temp)
{
    if(root==nullptr)return;
    if(root->left == nullptr && root->right == nullptr)
    {
        ans = min(ans,temp);
        temp = 0;
    }
    temp++;
    solve(root->left,ans,temp);
    solve(root->right,ans,temp);
}
int minDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MAX;
    int temp = 1;
    solve(root,ans,temp);
    return ans;
}