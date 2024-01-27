/* https://www.interviewbit.com/problems/reverse-linked-list/ */
#include<bits/stdc++.h>
#include<string>
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    ListNode * prev = NULL;
    ListNode * curr  = head;
    ListNode * forward = NULL;
    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
