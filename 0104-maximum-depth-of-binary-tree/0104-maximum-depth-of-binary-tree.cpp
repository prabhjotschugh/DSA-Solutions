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
    int hmax = 0;
    int height(TreeNode* root, int h){
        hmax = max(h, hmax);
        if(root->left){
            height(root->left, h+1);
        }
        if(root->right){
            height(root->right, h+1);
        }
        return hmax;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return height(root, 1);
    }
};