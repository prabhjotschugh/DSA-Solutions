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
    vector<int> ans;
    vector<int> findInorder(TreeNode* root){
        if(root == NULL){
            return ans;
        }
        
        if(root->left)
            findInorder(root->left);
        ans.push_back(root->val);
        if(root->right)
            findInorder(root->right);
        
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder = findInorder(root);
        
        for(int i=1;i<inorder.size();i++){
            if(inorder[i] <= inorder[i-1]){
                return 0;
            }
        }
        return 1;
    }
};