// https://www.interviewbit.com/problems/intersection-of-linked-lists/

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
ListNode *getIntersectionNode(ListNode *A, ListNode *B)
{
    ListNode *temp1 = A;
    ListNode *temp2 = B;
    while (temp1 != temp2)
    {
        if (temp1 == NULL)
        {
            temp1 = B;
        }
        else
        {
            temp1 = temp1->next;
        }
        if (temp2 == NULL)
        {
            temp2 = A;
        }
        else
        {
            temp2 = temp2->next;
        }
    }
    if (temp2 != NULL)
    {
        return temp2;
    }
}