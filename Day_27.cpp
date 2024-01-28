/* https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/ */


#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    *int val;
    *ListNode *next;
    *ListNode(int x) : val(x), next(NULL){}

};

ListNode *deleteDuplicates(ListNode *A)
{
    ListNode *head = new ListNode(0);
    head->next = A;
    ListNode *prev = head;
    ListNode *p = A;
    while (p && p->next)
    {
        ListNode *q = p->next;
        while (q && p->val == q->val)
        {
            ListNode *r = p->next;
            while (r && p->val == r->val)
            {
                r = r->next;
            }
            p = r;
            if (p)
            {
                q = p->next;
            }
            else
            {
                q = nullptr;
            }
        }
        prev->next = p;
        prev = prev->next;
        if (q)
        {
            p = q;
        }
    }
    return head->next;
}