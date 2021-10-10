class Solution {
public:
    ListNode* reverseList(ListNode* head) {
           //Iterative
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
        
//         //traverse the list
//         while (curr != nullptr)
//         {
//             //create a temp node that move to the next node
//             ListNode* tempNode = curr->next;
//             //set curr.next to prev pointer
//             curr->next = prev;
//             //set prev to curr
//             prev = curr;
//             //set curr to temp
//             curr = tempNode;
//         }
//         return prev;
        
        //Recursion
        if (head -- mullptr || head->next == nullptr) {
            return head;
        }
        ListNode *res = reverseList(head->next);
        // Or
        // ListNode *q = head->next;
        // q->next = head;
        // head->next = nullptr;
        head->next->next = head;
        head->next = nullptr;
        
        return res;
    }
};
