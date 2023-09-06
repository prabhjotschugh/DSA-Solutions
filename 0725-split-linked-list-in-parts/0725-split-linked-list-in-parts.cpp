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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> answer(k, nullptr);
        int length = 0;

        ListNode* temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }

        int partSize = length/k;
        int remaining = length%k;

        ListNode* node = head;
        ListNode* prev = nullptr;

        for(int i = 0; node && i < k; i++){
            answer[i] = node;
            for(int j = 0; j < partSize; j++){
                prev = node;
                node = node->next;
            }
            if(remaining > 0){
                prev = node;
                node = node->next;
                remaining--;
            }
            prev->next = nullptr;
        }
        return answer;
    }
};