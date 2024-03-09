// https://www.interviewbit.com/problems/level-order/



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
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> tem;
    while (!q.empty())
    {

        if (q.front() == NULL)
        {
            q.pop();
            ans.push_back(tem);
            tem.clear();
            if (q.size())
                q.push(NULL);
            else
                break;
        }
        TreeNode *root = q.front();
        q.pop();

        int root_val = root->val;

        tem.push_back(root_val);

        if (root->left)
        {
            q.push(root->left);
        }
        if (root->right)
        {
            q.push(root->right);
        }
    }
    return ans;
}