/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
*/

#include<iostream>
using namespace std;


//Brute force
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }

        if(cnt==n){
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }

        int res = cnt-n;

        temp = head;

        while(temp!=NULL){
            res--;
            if(res==0){
                break;
            }
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);

        return head;
}

//Optimal solution using fast and slow pointers
//T.C = O(len)
//S.C = O(1)

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
           return NULL;
        }
        int cnt = 0;
        ListNode* temp = head;

        // Count the number of nodes in the linked list
        while (temp != NULL) {
           cnt++;
           temp = temp->next;
        }

        // If N equals the total number of
        // nodes, delete the head
        if (cnt == n) {
           ListNode* newhead = head->next;
           delete (head);
           return newhead;
        }

        // Calculate the position of the node to delete (res)
        int res = cnt - n;
        temp = head;

       // Traverse to the node just before the one to delete
        while (temp != NULL) {
            res--;
            if (res == 0) {
             break;
            }
            temp = temp->next;
        }

        // Delete the Nth node from the end
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete (delNode);
        return head;
}