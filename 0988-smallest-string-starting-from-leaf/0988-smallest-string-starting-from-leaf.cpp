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
    vector<string> ans;
    void solve(TreeNode *root,string z){
        if(root == NULL) return;
        char ch = root->val+'a';
        if(root->left == NULL && root->right == NULL){
            ans.push_back(ch+z);
            return;
        }
        if(root->left) solve(root->left,ch+z);
        if(root->right) solve(root->right,ch+z);
    }
    string smallestFromLeaf(TreeNode* root) {
        string z="";
        solve(root,z);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};