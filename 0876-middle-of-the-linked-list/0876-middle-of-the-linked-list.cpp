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
    
    ListNode* middleNode(ListNode* head) {
        
        int n = getCount(head, 0);
        
        for(int i=0;i<n/2;i++){
            head = head->next;
        }
        return head;
    }
};