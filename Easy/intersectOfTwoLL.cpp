/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:


Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Example 2:
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Two Pointer
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        while (p1 != p2) { //loops until p1 is equal to p2
            
            // p1 == nullptr ? p1 = headB : p1 = p1->next;
            // p2 == nullptr ? p2 = headA : p2 = p2->next;
               
            if (p1 == nullptr) {
                p1 = headB;  //if p1 reaches nullptr first, then set it to headB
            } else {
                p1 = p1->next;
            }
            
            if (p2 == nullptr) {
                p2 = headA;  //if p1 reaches nullptr first, then set it to headA
            } else {
                p2 = p2->next;
            }
        }
        return p1;
        
//         //Hash Set
//         unordered_set<ListNode*> set;
//         //Add all values in headB to set
//         while (headB != nullptr) {
//             set.insert(headB);
//             headB = headB->next;
//         }
        
//         //look through headA and check if set contains headA in set
//         while (headA != nullptr) {
//             if (set.find(headA) != set.end()) {
//                 return headA;
//             }
//             headA = headA->next;
//         }
//         return nullptr;
    }
};


/*
listA = [4,1,8,4,5] size = 5
listB = [5,6,1,8,4,5] size = 6 => extra node before intersect

since listB have a greater length, we want to initialize p2 at the difference between listB and listA

p1 = 4
p2 = 6

move p1 and p2, if they are equal, return the node

listA = [4,1,8,4,5]
listB = [5,6,1,8,4,5]



Traverse list b and add to set
traverse list a and check if it is in set, return the value if it is in set

























*/
