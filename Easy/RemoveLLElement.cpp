class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //Edge Case: Empty List
        if (head == nullptr)
        {
            return head;
        }
        
        
        //create a sentinel node (act as an edge case when val is in the start of the         list)   
        ListNode* sentinel = new ListNode (0);
        
        //connect sentinel node to list
        sentinel->next = head;
        
        //create a curr ptr
        ListNode* curr_ptr = head;
        //create a prev ptr and set it to sentinel
        ListNode* prev_ptr = sentinel;    
        //create a node_to_delete ptr and set it to nullptr
        ListNode* node_to_delete_ptr = nullptr;
        
        //loop until the end of list
        while (curr_ptr != nullptr)
        {
            //if the val of curr is equal to val
            if (curr_ptr->val == val)
            {
                //set prev->next = curr->next 
                prev_ptr->next = curr_ptr->next;
                //set node_to_delete_ptr to curr
                node_to_delete_ptr = curr_ptr;
            }
            else 
            {
                //set prev = curr
                prev_ptr = curr_ptr;
            }
            //move curr to next 
            curr_ptr = curr_ptr -> next;
            
            //delete the node with val 
            if (node_to_delete_ptr != nullptr)
            {
                //delete the node_to_delete_ptr 
                delete node_to_delete_ptr;
                //set node_to_delete_ptr to nullptr
                node_to_delete_ptr = nullptr;
            }
        }
        //create a new list that points to head
        ListNode* solution = sentinel->next;
        //delete sentinel
        delete sentinel;
        
        return solution;
    }
};
