#include<bits/stdc++.h> 

using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode* head) {
    int sum = 0;
    int i = 0;
    while (head != NULL) {
        sum += head->val * pow(2, i);
        head = head->next;
        i++;
    }
    return sum;
}

int getDecimalValue2(ListNode* head) {
    int num = head->val; 
    while (head->next != NULL) {
        num = (num << 1) + head->next->val;
        head = head->next;
    }
    return num;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    cout << getDecimalValue2(head);

    cout << endl;

    ListNode* head2 = new ListNode(0);
    cout << getDecimalValue(head2);

    return 0; 
}