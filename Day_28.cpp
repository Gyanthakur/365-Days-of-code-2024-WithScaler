/* https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/ */

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode * RemoveDuplicate(ListNode * head)
{
    if(head == NULL || head -> next == NULL) return head;

    ListNode * curr  = head;
    while(curr != NULL)
    {
        if(curr -> next != NULL && curr -> val == curr -> next -> val)
        {
            ListNode * next_next = curr -> next -> next;
            ListNode * dele = curr ->next;
            delete(dele);
            curr -> next = next_next;
        }
        else
            curr = curr -> next;
    }
    return head;
}