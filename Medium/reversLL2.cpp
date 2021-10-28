/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return nullptr; 
        
        ListNode* curr = head, *prev = nullptr; 
        
        //traverse curr and prev to start of reversal
        while (left > 1) {
            prev = curr; 
            curr = curr->next; 
            left--; 
            right--; 
        }
        
        //two pointer that will fix final connection
        ListNode* con = prev, *tail = curr; 
        
        //reversal 
        ListNode* temp = nullptr;
        while (right > 0) {
            temp = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = temp; 
            right--; 
        }
        
        //connect con to the last element of reversal 
        /*
            7 -> 9 <- 2 <- 10 <- 1 <- 8 -> 6
                con  tail            prev  curr
            con->next = prev
            
            
            7 -> 9 -> 8 -> 1 -> 10 -> 2      6 
                         tail   curr
                         
            tail -> next = curr
            
            7 -> 9 -> 8 -> 1 -> 10 -> 2 -> 6 
        
        */
        if (con != nullptr) {
            con->next = prev; 
        } else {
            head = prev; 
        }
        
        /*
            7 -> 9 -> 8 -> 1 -> 10 -> 2      6 
                 tail   curr
                         
            tail -> next = curr
            
            7 -> 9 -> 8 -> 1 -> 10 -> 2 -> 6 
        */
        
        tail->next = curr; 
        return head; 
    }
};

// Another Solution: 

class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       
       if (head == nullptr) return nullptr;
       ListNode * dummy = new ListNode(0);
       dummy->next = head;
       
       ListNode* pre = dummy;

       //move pre to the index before reverse
       for (int i = 0; i < m-1; i++) {
           pre = pre->next;
       }
       
       //first position to reverse
       ListNode *start = pre->next;
       ListNode *startRev = start->next;
       
       // https://www.youtube.com/watch?v=wk8-_M-2fzI
       for (int i = 0; i < n-m; i++) {
           start->next = startRev->next;
           startRev->next = pre->next;
           pre->next = startRev;
           startRev = start->next;
           cout << endl;
       }
       return dummy->next;
   }
};
