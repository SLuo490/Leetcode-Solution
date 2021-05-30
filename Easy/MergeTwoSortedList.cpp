class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //if list 1 is empty, return list 2
        if (!l1)
        {
            return l2;
        }
        //if list 2 is empty, return list 1
        else if (!l2)
        {
            return l1;
        }
        //if both is empty, return null
        else if (!l1 && !l2)
        {
            return NULL;
        }
        //recursive
        else if (l1->val < l2->val)
        {
            //recursive l1
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else 
        {
            //recursive l2
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
            
        }
        
    }
};
