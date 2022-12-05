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
    int getCount(ListNode* head, int count=0){
        if(head==NULL){
            return count;
        }
        return getCount(head->next, count+1);
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* temp = head;
        int n = getCount(head, 0);

        for(int i=0;i<n/2-1;i++){
            head=head->next;
        }
        head->next = (head->next)->next;
        return temp;
        
    }
};