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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1, s2, ans;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(s1.size() || s2.size()){
            int temp = 0;
            if(s1.size()){
                temp += s1.top();
                s1.pop();
            }
            if(s2.size()){
                temp += s2.top();
                s2.pop();
            }
            temp += carry;
            carry = temp/10;
            temp = temp%10;

            ans.push(temp);
        }

        if(carry){
            ans.push(carry);
        }
        ListNode* head = new ListNode();
        ListNode* prev = head;
        while(ans.size()){
            ListNode* curr = new ListNode(ans.top());
            prev->next = curr;
            prev = prev->next;
            ans.pop(); 
        }
        return head->next;
    }
};