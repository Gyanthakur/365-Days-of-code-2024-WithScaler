// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/



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
ListNode* swapPairs(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast=A;
    if(A->next ==NULL) return A;
    while(slow!= NULL && slow->next != NULL ){
         
        if(fast->next->next !=NULL){
            fast=slow->next;
        int temp=slow->val;
        slow->val=fast->val;
        fast->val=temp;
        slow=slow->next->next;
        }else{
            fast=slow->next;
           int temp=slow->val;
        slow->val=fast->val;
        fast->val=temp;
        slow=slow->next->next;
        }
    }
    return A;
}