// https://www.interviewbit.com/problems/insertion-sort-list/

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

ListNode *insertionSortList(ListNode *A)
{

    ListNode *temp = A;

    while (temp != NULL)
    {

        ListNode *trav = A;

        while (trav != temp)
        {

            if (trav->val > temp->val)
            {

                swap(trav->val, temp->val);
            }

            trav = trav->next;
        }

        temp = temp->next;
    }

    return A;
}