// https://www.interviewbit.com/problems/preorder-traversal/



#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 void preOrde(TreeNode* root, vector<int>&ans)
 {
     if(root==NULL)return;
     ans.push_back(root->val);
     preOrde(root->left,ans);
     preOrde(root->right,ans);
 }
vector<int> preorderTraversal(TreeNode* A) {
    vector<int>ans;
    preOrde(A,ans);
    return ans;
}
