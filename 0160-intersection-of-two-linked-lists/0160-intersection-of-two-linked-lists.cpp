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
        ListNode* temp = headA;
        
        while(temp->next){
            temp = temp->next;
        }
        temp->next = headB;
        
        ListNode* slow = headA;
        ListNode* fast = headA;
        ListNode* start = headA;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(slow != start){
                    slow = slow->next;
                    start = start->next;
                }
                temp->next = NULL;
                return start;
            }
        }
        temp->next = NULL;
        return NULL;
    }
};