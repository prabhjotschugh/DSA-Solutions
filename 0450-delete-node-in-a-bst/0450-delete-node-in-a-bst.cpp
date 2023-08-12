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
    int maxValue(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else{
            if(root->left==NULL || root->right==NULL){
                TreeNode* node = root->left != NULL ? root->left : root->right;
                delete root;
                return node;
            }
            
            int maxi = maxValue(root->left);
            root->val = maxi;
            root->left = deleteNode(root->left, maxi); 
        }
        return root;
    }
};