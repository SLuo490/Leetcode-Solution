class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        //traverse the list
        while (curr != nullptr)
        {
            //create a temp node that move to the next node
            ListNode* tempNode = curr->next;
            //set curr.next to prev pointer
            curr->next = prev;
            //set prev to curr
            prev = curr;
            //set curr to temp
            curr = tempNode;
        }
        return prev;
    }
};
