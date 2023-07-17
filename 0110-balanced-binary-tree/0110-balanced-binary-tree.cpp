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
    bool flag = 1;
    int solve(TreeNode* root, int height){
        if(root == NULL)
            return height;
        
        int leftAns = solve(root->left, height+1);
        int rightAns = solve(root->right, height+1);
        
        if(abs(leftAns - rightAns) > 1){
            flag = 0;
        }
        return max(leftAns, rightAns);
    }
    bool isBalanced(TreeNode* root) {
        solve(root, 0);
        return flag;
    }
};