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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode *tortoise = head;
        ListNode *hare = head;
        ListNode *start = head;

        while(hare->next && hare->next->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(tortoise == hare){ 
                while(tortoise != start){
                    tortoise = tortoise->next;
                    start = start->next;
                }
                return start;
            }
        }
        return NULL;
    }
};