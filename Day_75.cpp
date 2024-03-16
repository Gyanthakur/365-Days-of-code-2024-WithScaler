// https://www.interviewbit.com/problems/reorder-list/


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
ListNode* reverse(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* small = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return small;
}

ListNode* reorderList(ListNode* A) {
    if(A == NULL || A->next == NULL) {
        return A;
    }
    ListNode* slow, *fast, *prev;
    slow = fast = A;
    while(fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = NULL;
    fast = reverse(slow);
    slow = A;
    prev = A;
    bool b = false;
    while(A && fast) {
        if(b == false) {
            A = A->next;
            prev->next = fast;
            prev = fast;
            b = true;  
           
        }
        else {
            fast = fast->next;
            prev->next = A;
            prev = A;
            b = false;  
           
        }
    }
    return slow;
   
}