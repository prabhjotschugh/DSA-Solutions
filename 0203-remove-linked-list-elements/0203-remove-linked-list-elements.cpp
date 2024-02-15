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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = new ListNode(-1);
        newHead->next=head;
        ListNode* prev = newHead;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val==val){
                ListNode *deleteNode = curr;
                prev->next=curr->next;
                curr=curr->next;
                delete(deleteNode);
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return newHead->next;
    }
};