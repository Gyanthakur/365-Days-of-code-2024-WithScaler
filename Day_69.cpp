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
ListNode *reverseBetween(ListNode *head, int B, int C)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *StartEle = head;
    ListNode *lastEle = head;
    ListNode *prevEle = head;
    int left = 1;
    while (left < B)
    {
        prevEle = StartEle;
        StartEle = StartEle->next;
        left++;
    }

    int right = 1;

    while (right <= C)
    {
        lastEle = lastEle->next;
        right++;
    }
    ListNode *prev = NULL;
    ListNode *curr = StartEle;
    ListNode *forward = NULL;

    int count = 1;

    while (count <= C - B + 1)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count += 1;
    }

    if (prevEle == StartEle)
    {
        head = prev;
    }
    else
    {
        prevEle->next = prev;
    }
    StartEle->next = curr;
    return head;
}
