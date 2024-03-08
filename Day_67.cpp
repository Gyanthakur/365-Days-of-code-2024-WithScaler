// https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
};
void connect(TreeLinkNode *A)
{
    TreeLinkNode *prev;
    queue<TreeLinkNode *> q;
    q.push(A);
    while (q.size() > 0)
    {
        int sz = q.size();
        prev = NULL;
        for (int i = 0; i < sz; i++)
        {
            TreeLinkNode *temp = q.front();
            q.pop();
            if (prev == NULL)
            {
                prev = temp;
            }
            else
            {
                prev->next = temp;
                prev = temp;
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        prev->next = NULL;
    }
}
