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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL,*nxt=NULL;
        while(head){
            nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);int x=head->val;
        ListNode* tmp=new ListNode(0),*prev=tmp;
        while(head!=NULL){
            while(head!=NULL && head->val<x){head=head->next;}
            if(head==NULL){tmp->next=NULL;break;}
            x=head->val;
            tmp->next=head;tmp=tmp->next;head=head->next;
        }
        return reverse(prev->next);
    }
};