// https://www.interviewbit.com/problems/least-common-ancestor/

#include <bits/stdc++.h>
using namespace std;
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool chck(TreeNode *A, int B)
{
    if (!A)
        return false;
    if (A->val == B)
        return true;

    else
        return chck(A->left, B) || chck(A->right, B);
}
TreeNode *solve(TreeNode *A, int B, int C)
{
    if (!A)
        return NULL;
    if (A->val == B)
    {
        return A;
    }
    if (A->val == C)
    {
        return A;
    }
    TreeNode *lt = solve(A->left, B, C);
    TreeNode *rt = solve(A->right, B, C);

    if (lt && rt)
        return A;

    if (lt)
        return lt;

    if (rt)
        return rt;

    return NULL;
}
int lca(TreeNode *A, int B, int C)
{
    int both_exist = 0;
    both_exist = chck(A, B) && chck(A, C);
    TreeNode *ans = solve(A, B, C);

    if (ans && both_exist)
        return ans->val;
    return -1;
}