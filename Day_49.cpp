// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/



#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    bool leftToRight = 1;
    if(root == NULL)return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++)
        {
            TreeNode * topNode = q.front();
            q.pop();
            int index = leftToRight ? i : size-i-1;
            temp[index] = topNode->val;
            if(topNode->left)
                q.push(topNode->left);
            if(topNode->right)
                q.push(topNode->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(temp);
       
    }
    return ans;
}
