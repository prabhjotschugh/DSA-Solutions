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
    int listLength(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)    return head;
        int n = listLength(head);
        k = k%n;
        
        if(k==0)    return head;
        
        ListNode*  temp = head;
        ListNode* prev = NULL;
        int shift = n-k;
        while(shift--){
            prev = temp;
            temp = temp->next;
        }
        ListNode* newHead = temp;
        
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        prev->next = NULL;
        
        return newHead;
    }
};