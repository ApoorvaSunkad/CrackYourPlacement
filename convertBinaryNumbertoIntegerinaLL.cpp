/*
Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include<iostream>
#include<vector>
using namespace std;
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next == NULL){
        return head;
    }

    ListNode* curr = head;
    ListNode* prev = NULL;

    while(curr!=NULL){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
 int getDecimalValue(ListNode* head) {
    ListNode* temp = reverseList(head);
    int X , total = 0, i = 0;
    while(temp!=NULL){
        X = temp->val;
        total = total+pow(2,i)*X;
        i++;
        temp = temp->next;
    }
    return total;
}