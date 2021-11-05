/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
*/

class Solution {
public:
    
    //Cleaner solution
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head; 
        ListNode* slow = head; 
        
        //traverse fast nth node away from slow
        for (int i = 1; i <= n; i++) {
            fast = fast->next; 
        }
        
        //if fast == nullptr, then the node to remove is at the beginning, so return head->next; 
        if (!fast) return head->next; 
        
        //increment slow and fast until fast reach nullptr
        while (fast->next) {
            fast = fast->next; 
            slow = slow->next; 
        }
        
        //connect slow to slow->next->next
        slow->next = slow->next->next; 
        return head; 
    }
  
  
    //My solution
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //if list contain 1 element and n == 1, return nullptr
        if (head->next == nullptr && n == 1) {
            return nullptr; 
        }
    
        // find the size of the list
        int sz = 0; 
        ListNode* ptr = head; 
        while (ptr != nullptr) {
            sz++;
            ptr = ptr->next; 
        }
        
        //If n is equal to size of the list, then we need to remove the first element
        if (sz == n) {
            return head->next; 
        }
        
        int traversal = sz - 1 - n; 
        //traverse curr to the node to remove
        ListNode* curr = head; 
        while (traversal != 0) {
            curr = curr->next; 
            traversal--; 
        }
        
        //"delete" the node
        curr->next = curr->next->next; 
        
        return head;
    }
};
