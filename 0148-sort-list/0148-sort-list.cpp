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
        ListNode* merger(ListNode* head1, ListNode* head2){
        if(head1 == NULL)
            return head2;
            
        if(head2 == NULL)
            return head1;
            
        if(head1->val <= head2->val){
            head1->next = merger(head1->next, head2);
            return head1;
        }else{
            head2->next = merger(head1, head2->next);
            return head2;
        }
    }
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* ans = merger(left, right);
        return ans;
    }
};