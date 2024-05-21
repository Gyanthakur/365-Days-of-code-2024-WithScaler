// https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

#include <bits/stdc++.h>
using namespace std;
int maxi = INT_MIN;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode *A)
{
    if (A == NULL)
        return 0;

    int ans = 0;
    int left = max(0, solve(A->left));
    int right = max(0, solve(A->right));
    ans = left + right + A->val;
    maxi = max(ans, maxi);
    return max(max(A->val + right, A->val + left), A->val);
}

int maxPathSum(TreeNode *A)
{
    maxi = INT_MIN;
    solve(A);
    return maxi;
}