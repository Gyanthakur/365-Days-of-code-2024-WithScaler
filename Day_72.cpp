// https://www.interviewbit.com/problems/rotate-list/

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
ListNode *rotateRight(ListNode *A, int B)
{
    ListNode *curr = A;
    int count = 1;
    while (curr->next && ++count)
    {
        curr = curr->next;
    }
    curr->next = A;
    B = B % count;
    B = count - B;
    while (B--)
    {
        curr = curr->next;
    }
    A = curr->next;
    curr->next = NULL;
    return A;
}
