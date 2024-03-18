// https://www.interviewbit.com/problems/list-cycle/

#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right, *next;
    ListNode(int x) : val(x), left(NULL), right(NULL) {}
};
ListNode *detectCycle(ListNode *A)
{
    ListNode *h = NULL;
    while (A != NULL)
    {
        if (A->val < 0)
        {
            A->val = abs(A->val);
            return A;
        }
        else
        {
            A->val = A->val * -1;
            A = A->next;
        }
    }
    h = A;
    return h;
}
