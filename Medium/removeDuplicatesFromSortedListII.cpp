/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
*/

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head); 
        ListNode* prev = dummy; 
        
        while (head != nullptr) {
            // if head and head->next contains the same number, traverse head->next to a non duplicate num 
            // and switch connections
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next; 
                }
                prev->next = head->next; 
            } else { // traverse prev to next ptr
                prev = prev->next; 
            } // traverse head to next ptr
            head = head->next; 
        }
        return dummy->next; 
    }
};

/*
0 -> 1 -> 2 -> 3 -> 3-> 4 -> 4 -> 5
-
-
     -

*/
