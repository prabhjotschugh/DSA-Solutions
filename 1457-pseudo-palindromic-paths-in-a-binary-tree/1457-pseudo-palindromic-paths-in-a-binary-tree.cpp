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
    void solve(TreeNode* root, unordered_set<int>st,int &ans){
        if(root==NULL)
            return;
        
        if(st.find(root->val)!=st.end())
            st.erase(root->val);
        else
            st.insert(root->val);

        if(root->left==NULL and root->right==NULL){
            if(st.size()<=1)
                ans++;
            
            return;
        }
        if(root->left)  solve(root->left,st,ans);
        if(root->right) solve(root->right,st,ans);
    }

    int pseudoPalindromicPaths(TreeNode* root){
        unordered_set<int>st;
        int ans=0;
        solve(root,st,ans);
        return ans;
    }
};