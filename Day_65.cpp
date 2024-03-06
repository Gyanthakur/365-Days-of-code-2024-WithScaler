// https : // www.interviewbit.com/problems/recover-binary-search-tree/

#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right, *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *A, vector<int> &res, int &minVal)
{
    if (!A)
    {
        return;
    }
    solve(A->right, res, minVal);
    minVal = min(minVal, A->val);
    if (A->val > minVal)
    {
        res[0] = minVal;
        res[1] = A->val;
    }
    solve(A->left, res, minVal);
}

vector<int> recoverTree(TreeNode *A)
{
    vector<int> res(2, 0);
    int minVal = INT_MAX;
    solve(A, res, minVal);
    return res;
}