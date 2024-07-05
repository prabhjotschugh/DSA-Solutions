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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        int i=1;
        int x0=head->val, x1=head->next->val;
        bool less=x1<x0, bigger=x1>x0;
        for(ListNode* Next=head->next->next; Next; i++, Next=Next->next){
            int x=Next->val;
            bool bigger1=x>x1, less1=x<x1;
            if((less && bigger1)||(bigger && less1)){
                pos.push_back(i);
            }
            bigger=bigger1;
            less=less1;
            x1=x;
        }
        int sz=pos.size();
        if (sz<=1) return {-1, -1};
        else{
            int maxD=pos.back()-pos[0];
            int minD=INT_MAX;
            for(int i=0; i<sz-1; i++)
                minD=min(minD, pos[i+1]-pos[i]);
            return {minD, maxD};
        }
    }
};