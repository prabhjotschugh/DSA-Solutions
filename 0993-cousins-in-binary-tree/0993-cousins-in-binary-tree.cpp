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
    int height_x = 0;
    int height_y = 0;
    TreeNode* parent_x = NULL;
    TreeNode* parent_y = NULL;
    
    void solve(TreeNode* root, int x, int y, int h, TreeNode* parent){
        if(root == NULL)
            return;
        
        if(root->val == x){
            height_x = h;
            parent_x = parent;
        }else if(root->val == y){
            height_y = h;
            parent_y = parent;
        }else{
            if(root->left)
                solve(root->left, x, y, h+1, root);
            if(root->right)
                solve(root->right, x, y, h+1, root);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root, x, y, 0, NULL);
        if((height_x == height_y) && (parent_x != parent_y))
            return true;
        
        return false;
    }
};