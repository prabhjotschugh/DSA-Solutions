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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        unordered_set<int> parents;
        int par= head->val;
        while(head){
            if(set.count(head->val)){
                parents.insert(par);
                head= head->next;
            }
            else{
                while(head && set.count(head->val)==0) head= head->next;
                if(!head) break;
                par= head->val;
            }
        }
        return parents.size();
    }
};