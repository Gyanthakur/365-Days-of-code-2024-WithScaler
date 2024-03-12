// https://www.interviewbit.com/problems/add-two-numbers-as-lists/





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
ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
    if(!head1) return head2;
    if(!head2) return head1;
    int carry = 0;
    ListNode* curr = new ListNode(-1);
    ListNode* temp = curr;
    while(head1 || head2 || carry){
        int sum = 0;
        if(head1){
            sum += head1->val;
            head1 = head1->next;
        }
        if(head2){
            sum += head2->val;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum/10;
        ListNode* t = new ListNode(sum%10);
        temp->next = t;
        temp = temp->next;
    }
    return curr->next;
}