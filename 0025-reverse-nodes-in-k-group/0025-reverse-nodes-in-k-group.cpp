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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int counter = 0;
        while(curr){
            curr = curr->next;
            counter++;
        }
        
        if(counter < k){
            return head;
        }
        
        curr = head;
        counter=0;
        
        while(curr && counter<k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            counter++;
        }
        
        if(forward)
            head->next = reverseKGroup(forward, k);
        
        return prev;
    }
};