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
    vector<int> l1, l2;
    void findLeaves(TreeNode* root, vector<int> &leaf){
        if(root==NULL)  return;
        else if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->val);
        }

        if(root->left){
            findLeaves(root->left, leaf);
        }
        if(root->right){
            findLeaves(root->right, leaf);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        findLeaves(root1, l1);
        findLeaves(root2, l2);
        if(l1.size()!=l2.size())    return false;
        else{
            for(int i=0;i<l1.size();i++){
                if(l1[i]!=l2[i])    return false;
            }
        }
        return true;
    }
};