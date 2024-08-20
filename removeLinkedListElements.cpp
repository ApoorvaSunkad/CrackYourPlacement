/*
Given the head of a linked list and an integer val, remove all the 
nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50


*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//T.C = O(N)
//S.C = O(1)

ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;

        while(temp!=NULL && temp->next != NULL){
            if(temp->next->val == val){
                ListNode* del = temp->next;
                temp->next = del->next;
                delete(del);
            }else{
                temp = temp->next;
            }
        }
        return dummy->next;
    }