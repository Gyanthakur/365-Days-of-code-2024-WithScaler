// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* flatten(TreeNode* A) {
            stack<TreeNode*> s;

            if(A==NULL)
            return A;

            TreeNode* x = new TreeNode(A->val);
            TreeNode* root = x;
            
            if(A->right)
            s.push(A->right);

            if(A->left)
            s.push(A->left);
            while(s.size())
           {
                      auto it=s.top();
                      x->right = s.top();
                      x->left = NULL;
                      x = x->right;
                      s.pop();
                   
                      if(it->right)
                      s.push(it->right);
                      if(it->left)
                      s.push(it->left);
           }
           return root;
}