/*
Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the 
sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer. 
Look at the printList() function in the driver code for more clarity.

Examples:

Input:

Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: The resultant linked lists has every node in a single level.
(Note: | represents the bottom pointer.)

Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation: The resultant linked lists has every node in a single level.
(Note: | represents the bottom pointer.)

Note: In the output section of the above examples, the -> represents the bottom pointer.

Expected Time Complexity: O(n * n * m)
Expected Auxiliary Space: O(n)

Constraints:
0 <= number of nodes <= 50
1 <= no. of nodes in sub-LinkesList(mi) <= 20
1 <= node->data <= 103


*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node* mergeLists(Node* head1, Node* head2){
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    Node* res;
    if(head1->data < head2->data){
        res = head1;
        res->bottom =  mergeLists(res->bottom,head2);
    }else{
        res = head2;
        res->bottom = mergeLists(head1,res->bottom);
    }
    return res;
}
    // Function which returns the  root of the flattened linked list.
Node *flatten(Node *root) {
    // Your code here
    if(root == NULL){
        return NULL;
    }
    Node* head2 = flatten(root->next);
    return mergeLists(root,head2);
}