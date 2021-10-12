/*
Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.
Your algorithm should not use any extra space and the input LinkedList should be modified in-place.

Example 1:
Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
Output: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null 

Example 2:
Input: 2 -> 4 -> 6 -> 8 -> 10 -> null
Output: 2 -> 10 -> 4 -> 8 -> 6 -> null
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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        
        while (curr!= nullptr) {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
    
    ListNode* middle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    //O(N) Time and O(1) Space
    bool isPalindrome(ListNode* head) {
        
        ListNode* middleLL = middle(head); //find the middle of the linked list
        ListNode* headOfRev = reverse(middleLL); //reverse the second half of the linked list
        
        ListNode* copySecondHalf = headOfRev; //ptr to reverse back to original linked list
        
        //check for palindrome
        ListNode *ptr = head;
        while (ptr != nullptr && headOfRev != nullptr) {
            if (ptr->val != headOfRev->val) {
                break;
            }
            ptr = ptr->next;
            headOfRev = headOfRev->next;
        }
        reverse(copySecondHalf);
        if (ptr == nullptr || headOfRev == nullptr) {
            return true;
        }
        return false; 
    }
};

/*
O(N) Time and Space Complexity
bool isPalindrome(ListNode* head) {
    vector<int> list;
    //adds linked list to array
    ListNode* ptr = head;
    while (ptr!=nullptr) {
        list.push_back(ptr->val);
        ptr = ptr->next;
    }

    //Checks for Palindrome in array
    int j = list.size() - 1;
    for (int i = 0; i < j; i++) {
        if (list[i] != list[j]) {
            return false;
        }
        j--;
    }

    return true;
}
*/
