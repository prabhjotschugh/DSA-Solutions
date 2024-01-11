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
    int ans = 0;
    void dfs(TreeNode* root, int n, int x){
        if(!root) return;
        if(!(n == INT_MAX || x == INT_MIN))
            ans = max({ans, abs(root->val - n), abs(root->val- x)});
        n = min(root->val, n);
        x = max(root->val, x);
        dfs(root->left, n, x);
        dfs(root->right, n, x);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MAX, INT_MIN);
        return ans;
    }
};