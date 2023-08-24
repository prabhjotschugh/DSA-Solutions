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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* curr = head;
        unordered_map<int, int> umap;
        
        while(curr){
            umap[curr->val]++;
            curr = curr->next;
        }
        
        curr = head;
        ListNode* prev = NULL;
        while(curr && head){
            if(umap[curr->val] > 1){
                if(prev == NULL){
                    head = head->next;
                    curr = curr->next;
                }else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};