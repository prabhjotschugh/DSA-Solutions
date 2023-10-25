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
    bool sum(TreeNode* root, int tgt , int temp){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            
            if(tgt==temp+root->val)return true;
            return false;
        }
        bool left=sum(root->left,tgt,temp+root->val);
        bool right=sum(root->right,tgt,temp+root->val);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int temp=0;
        return sum(root,targetSum,temp);
    }
};