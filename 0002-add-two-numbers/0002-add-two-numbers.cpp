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
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* ans = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return ans;
    }
    void insertAtTail(ListNode* &head, ListNode* &tail, int data){
        ListNode* temp = new ListNode(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }else{
            tail->next = temp;
            tail = temp;
            return;
        }
    }
    ListNode* addNodes(ListNode* first, ListNode* second){
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1=0;
            if(first)   
                val1 = first->val;
            
            int val2=0;
            if(second)  
                val2 = second->val;
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            if(first)
                first = first->next;
            if(second)
                second = second->next;
        }
        return ansHead;
    }
    
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        //first = reverse(first);
        //second = reverse(second);
        
        ListNode* ans = addNodes(first, second);
        
        //ans = reverse(ans);
        return ans;
    }
};