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
    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while (left != nullptr && right != nullptr) {
            if (left -> val < right -> val) {
                temp -> next = left;
                temp = temp -> next;
                left = left -> next;
            }
            else {
                temp -> next = right;
                temp = temp -> next;
                right = right -> next;
            }
        }
        while (left != nullptr) {
            temp -> next = left;
            temp = temp -> next;
            left = left -> next;
        }
        while (right != nullptr) {
            temp -> next = right;
            temp = temp -> next;
            right = right -> next;
        }
        return dummy -> next;
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int start, int end) {
        if (start == end) 
            return lists[start];
        int mid = start + (end - start) / 2;
        ListNode *left = mergeSort(lists, start, mid);
        ListNode *right = mergeSort(lists, mid + 1, end);
        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);
    }
};