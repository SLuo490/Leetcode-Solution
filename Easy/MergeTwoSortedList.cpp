/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //Edge Case
        if (!l1) return l2;
        if (!l2) return l1;
        if (!l1 && !l2) return nullptr;
        
        //Recursion
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    
    //Iteratively
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //edge cases
        if (!l1) return l2;
        if (!l2) return l1;
        if (!l1 && !l2) return nullptr;
        

        //result node with -1 node as the first element
        ListNode *reshead = new ListNode(-1);
        ListNode *res = reshead;
        
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l2->val <= l1->val) {
                res->next = l2;
                l2 = l2->next;
            } else {
                res->next = l1;
                l1 = l1->next;
            }
            res = res->next;
        }
        //res->next equal to l2 if l1 == nullptr else res->next = l1
        // res->next = l1 == nullptr ? l2 : l1;
        
        //add the rest of the element in either l1 or l2
        if (l1 == nullptr) {
            res->next = l2;
        } else {
            res->next = l1;
        }

        return reshead->next;
    }
};
