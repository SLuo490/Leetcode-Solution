/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Notice that you should not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //Hash Table
//         if (!head) {
//             return nullptr;
//         }
        
//         unordered_set<ListNode*> set;
        
//         while (head != nullptr) {
//             //if head is in set, return the node
//             if (set.find(head) != set.end()) {
//                 return head;
//             }
//             set.insert(head);
//             head = head->next;
//         } 
//         return nullptr;
        
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return slow;
        }

        return nullptr;
        
        
    }
};
