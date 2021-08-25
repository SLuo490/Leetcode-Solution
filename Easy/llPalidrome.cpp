/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
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
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        if (head == nullptr) return false;
        
        ListNode *curr = head;
        while (curr != nullptr)
        {
            res.push_back(curr->val);
            curr = curr->next;
        }
        
        //check the array to see if it is palindrome
        if (res.size() == 1) return true;
        for (int i = 0; i < res.size()/2; i++)
        {
            if (res[i] != res[res.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
