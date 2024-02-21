// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/



#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void recur(TreeNode *root, int sum, vector<int> &curr, vector<vector<int>> &ans){
     if(root == NULL) return;
     curr.push_back(root->val);
     if(root->left == NULL && root->right == NULL){
         if(sum == root->val)
             ans.push_back(curr);
         curr.pop_back();
         return;
     }
     
     recur(root->left, sum-root->val, curr, ans);
     recur(root->right, sum-root->val, curr, ans);
     curr.pop_back();
 }
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
   
    vector<vector<int>> ans;
    vector<int> curr;
    recur(A, B, curr, ans);
    return ans;
   
}