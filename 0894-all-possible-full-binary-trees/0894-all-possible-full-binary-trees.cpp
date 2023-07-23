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
    vector<vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int n) {
        if (n % 2 == 0)
            return {}; // Return empty vector for even n
        if (n == 1){
            dp[1]={new TreeNode()};
            return dp[1];
        }    
        if (dp[n].size()>0)
            return dp[n];

        vector<TreeNode*> ans;
        for (int i = 1; i <n; i += 2) {
            vector<TreeNode*> Left = solve(i);
            vector<TreeNode*> Right = solve(n - 1 - i);
            for (TreeNode* l : Left) {
                for (TreeNode* r : Right) {
                    TreeNode* root = new TreeNode();
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        dp.assign(n + 1, {}); 
        return solve(n);
    }
};