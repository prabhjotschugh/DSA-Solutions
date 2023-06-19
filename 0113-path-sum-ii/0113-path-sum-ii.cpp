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
    void solve(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>>  &ans){
        if(root == NULL){
            return;
        }
        
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL){
            long int sum = 0;
            int n = path.size();
            for(int i=0;i<n;i++){
                sum += path[i];
            }
            
            if(sum == targetSum){
                ans.push_back(path);
            }
        }
        
        if(root->left)  solve(root->left, targetSum, path, ans);
        if(root->right) solve(root->right, targetSum, path, ans);
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, path, ans);
        return ans;
    }
};