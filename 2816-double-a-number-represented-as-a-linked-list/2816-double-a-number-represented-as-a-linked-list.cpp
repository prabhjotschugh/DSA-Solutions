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
    ListNode* doubleIt(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != NULL) {
            int doubled_value = (curr->val << 1);
            if (doubled_value >= 10) {
                prev->val++;
                curr->val = doubled_value - 10;
            }
            else {
                curr->val = doubled_value;
            }
            prev = curr;
            curr = curr->next;
        }
        
        if (dummy->val == 0) return head;
        return dummy;
    }
};