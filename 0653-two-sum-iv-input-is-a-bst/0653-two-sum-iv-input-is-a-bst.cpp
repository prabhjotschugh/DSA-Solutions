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
    unordered_map<int, int> umap;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        
        int rem = k - root->val;
        if(umap.find(rem) != umap.end())
            return 1;
        
        umap[root->val]++;
        return (findTarget(root->left, k) || findTarget(root->right, k));
    }
};