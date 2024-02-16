// https://www.interviewbit.com/problems/postorder-traversal/


#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 void post(TreeNode * root, vector<int>&ans)
 {
     if(root == NULL)return;
     post(root->left,ans);
     post(root->right,ans);
     ans.push_back(root->val);
 }
vector<int> postorderTraversal(TreeNode* A) {
    vector<int>ans;
    post(A,ans);
    return ans;
}
