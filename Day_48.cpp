// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/



#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum =0;
void solve(TreeNode * root, string str)
{
    if(root==NULL)
    return;

    str+=to_string(root->val);
    str = to_string(stoi(str)%1003);

    if(root->left == nullptr && root ->right == nullptr)
        sum+=stoi(str)%1003;
    solve(root->left,str);
    solve(root->right,str);
}
int sumNumbers(TreeNode* A) {
    sum =0;
    solve(A,"");
    return sum%1003;
}
