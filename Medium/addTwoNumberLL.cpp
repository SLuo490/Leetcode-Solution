/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, x = 0, y = 0;
        ListNode *ans = new ListNode();
        ListNode *head = ans;
        
        //loop until both list is empty
        while (carry || l1 || l2)
        {
            if (l1)
            {
                //copy the first node in l1 into x
                x = l1->val;
                //move to the next node after you copy
                l1 = l1->next;
            }
            //if there is no more node in l1, set x to 0
            else 
            {
                x = 0;
            }
            if (l2)
            {
                //copy the first node in l2 into y
                y = l2->val;
                //move to the next node after you copy
                l2 = l2->next;
            }
            //if there is no more node in l2, set y to 0
            else {
                y = 0;
            }
            //calculate x + y + carry
            int temp = x + y + carry;
            //add the modulo of 10 into answer
            head->next = new ListNode(temp % 10);
            //move head to the next ptr
            head = head->next;
            //calculate the carry for the next calculation
            carry = temp/10;
        }
        return ans->next;
    }
};
