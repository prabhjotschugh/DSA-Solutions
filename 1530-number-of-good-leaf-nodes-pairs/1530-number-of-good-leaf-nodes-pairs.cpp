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
    int ans=0;
    vector<int> solve(TreeNode* root,int d){
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) return {1};
        auto l=solve(root->left,d);
        auto r=solve(root->right,d);
        for(auto ll:l){
            for(auto rr:r){
                if(ll+rr<=d) ans++;
            }
        }
        vector<int> curr;
        for(auto it:l) {
            if(1+it<=d) curr.push_back(it+1);
        }
        for(auto it:r) {
            if(1+it<=d) curr.push_back(it+1);
        }
        return curr;
    }
    
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return ans;
    }
};