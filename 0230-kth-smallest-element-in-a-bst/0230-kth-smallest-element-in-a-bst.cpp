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
    void inorderTraversal(TreeNode* root, vector<int>& ans){
        if(root == NULL)
            return;
        
        if(root->left)
            inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        if(root->right)
            inorderTraversal(root->right, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans[k-1];
    }
};