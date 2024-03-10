// https://www.interviewbit.com/problems/reverse-link-list-ii/

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
ListNode *reverseBetween(ListNode *A, int B, int C)
{
    if (A == NULL || A->next == NULL)
        return A;

    ListNode *m = A;
    ListNode *n = A;
    ListNode *x = A;
    int b = 1;
    while (b < B)
    {
        x = m;
        m = m->next;
        b += 1;
    }

    int c = 1;

    while (c <= C)
    {
        n = n->next;
        c += 1;
    }

    ListNode *p = NULL;
    ListNode *q = m;
    ListNode *r;

    int count = 1;

    while (count <= C - B + 1)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
        count += 1;
    }

    if (x == m)
    {
        A = p;
    }
    else
    {
        x->next = p;
    }
    m->next = q;
    return A;
}