/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& pre, vector<int>& post, int& index, int start, int end, int n){
        if(index >= n || start > end){
            return NULL;
        }
        
        int ele = pre[index++];
        TreeNode* root = new TreeNode(ele);
    
        if(start == end)
            return root;
        
        int i = 0;
        for(i=start; i<=end; i++){
            if(post[i] == pre[index]){
                break;
            }
        }
        
        root->left = solve(pre, post, index, start, i, n);
        root->right = solve(pre, post, index, i+1, end-1, n);   

        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        int preIndex = 0;
        TreeNode* head = solve(pre, post, preIndex, 0, n-1, n);
        return head;
    }
};