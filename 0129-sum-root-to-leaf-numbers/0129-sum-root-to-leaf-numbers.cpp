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
    #define ll long long int
    void path(TreeNode* root, int& ans, int pathSum){
        pathSum = (pathSum*10) + root->val;
        
        if(root->left == NULL && root->right == NULL){
            ans += pathSum;
        }
        
        if(root->left)
            path(root->left, ans, pathSum);
        if(root->right)
            path(root->right, ans, pathSum);
            
        pathSum = 0;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        path(root, ans, 0);
        return ans;
        
    }
};