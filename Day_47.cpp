// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/






#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pre(TreeNode * root, vector<int> &ans)
 {
     if(root == NULL)return;
     ans.push_back(root->val);
     pre(root->left,ans);
     pre(root->right,ans);
 }
 void post(TreeNode * root, vector<int> &ans)
 {
     if(root == NULL)return;
     pre(root->left,ans);
     pre(root->right,ans);
     ans.push_back(root->val);
 }
TreeNode* buildTree(vector<int> &A) {
    // sort (begin(A),end(A));
    // // reverse(begin(A),end(A));
    
    // TreeNode * root = new TreeNode(A[0]);
    // TreeNode * curr = root;
    // for(int i=1;i<A.size();i++)
    // {
    //     TreeNode * temp = new TreeNode(A[i]);
    //     curr -> left = temp;
    //     curr->right = NULL;
    //     curr = temp;
    // } 
    // curr -> left = NULL;
    // curr -> right = NULL;
    // // return root;
    
    // vector<int>pr,pos;
    // pre(root,pr);
    // post(root,pos);
    // return pr;
    // return pos;
    
    
    stack<TreeNode*> s;
    TreeNode* root = nullptr;
    for (int num : A) {
        TreeNode* curr = new TreeNode(num);
        while (!s.empty() && s.top()->val < num) {
            curr->left = s.top();
            s.pop();
        }
        if (s.empty()) {
            root = curr;
        } else {
            s.top()->right = curr;
        }
        s.push(curr);
        }

    return root;
    
}
