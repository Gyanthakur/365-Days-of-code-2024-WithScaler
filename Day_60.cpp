// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildBinaryTree(vector<int>& inorder,int instart,int inend, vector<int>& preorder,int prestart,int preend,map<int,int>&mp){

        if(instart>inend || prestart>preend) return NULL;


        TreeNode* root = new TreeNode(preorder[prestart]);


        int inroot = mp[preorder[prestart]];

        int num = inroot-instart;


        root->left = buildBinaryTree(inorder,instart,inroot-1,preorder,prestart+1,prestart+num,mp);

        root->right = buildBinaryTree(inorder,inroot+1,inend,preorder,prestart+num+1,preend,mp);


        return root;

    }


TreeNode* buildTree(vector<int> &pre, vector<int> &in) {

    map<int,int>mp;

        for(int i=0;i<in.size();i++){

            mp[in[i]] = i;

        }


        return buildBinaryTree(in,0,in.size()-1,pre,0,pre.size()-1,mp);

    

}
