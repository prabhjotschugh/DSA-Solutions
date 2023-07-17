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
    int findHeight(TreeNode* root, int height){
        if(root == NULL)
            return height;
        
        int leftAns = findHeight(root->left, height+1);
        int rightAns = findHeight(root->right, height+1);
        
        return max(leftAns, rightAns);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return findHeight(root, 0);
    }
};