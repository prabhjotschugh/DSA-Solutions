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
    int findLength(ListNode* head, int count=0){
        if(head==NULL){
            return count;
        }
        return findLength(head->next,count+1);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* extra = head;
        int len = findLength(head,0);
        if(n==1 && len==1) return NULL;
        else if(len==n){
            return head->next;
        }
        for(int i=0;i<len-n-1;i++){
            temp=temp->next;
        }
        for(int i=0;i<len-n;i++){
            extra=extra->next;
        }
        (temp->next)=(extra->next);
        return head;
    }
};