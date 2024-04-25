// https://www.interviewbit.com/problems/merge-k-sorted-lists/



#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *left, *next;
    ListNode *right;
    ListNode(int x) : val(x), left(NULL), right(NULL) {}
};
ListNode *mergeKLists(vector<ListNode *> &A)
{
    // Min heap
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
    int k = A.size();
    for (int i = 0; i < k; i++)
    {
        pq.push({A[i]->val, A[i]});
    }
    ListNode *head = new ListNode(pq.top().first);
    ListNode *temp = head;
    ListNode *del = pq.top().second;
    del = del->next;
    pq.pop();
    if (del != NULL)
    {
        pq.push({del->val, del});
    }
    while (!pq.empty())
    {
        auto ele = pq.top();
        pq.pop();
        ListNode *curr = ele.second;
        temp->next = curr;
        temp = temp->next;
        curr = curr->next;
        if (curr != NULL)
        {
            pq.push({curr->val, curr});
        }
    }
    temp->next = NULL;
    return head;
}