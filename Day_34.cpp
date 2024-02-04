/*  https://www.interviewbit.com/problems/inorder-traversal/ */

#include <bits/stdc++.h>
using namespace std;
struct Instruction
{
    TreeNode *t;
    bool i;

    Instruction(TreeNode *a, bool b) : t(a), i(b) {}
};

// * Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *A)
{
    vector<int> ans;
    stack<Instruction> s;
    s.push(Instruction{A, false});
    while (!s.empty())
    {
        Instruction i = s.top();
        s.pop();
        if (i.t == NULL)
        {
            continue;
        }

        // recurse
        if (i.i == false)
        {
            s.push(Instruction(i.t->right, false));
            s.push(Instruction(i.t, true));
            s.push(Instruction(i.t->left, false));
        }
        // process
        if (i.i == true)
        {
            ans.push_back(i.t->val);
        }
    }
    return ans;
}