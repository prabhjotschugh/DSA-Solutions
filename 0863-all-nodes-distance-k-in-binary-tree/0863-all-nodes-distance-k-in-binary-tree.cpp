/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>a;
    void depth(TreeNode* root,int k){
        if(!root)return;
        if(k==0)a.push_back(root->val);
        depth(root->left,k-1);
        depth(root->right,k-1);
    }
    int c(TreeNode* root,TreeNode* target,int k){
        if(!root){
            return -1;
        }
        if(root==target){
            depth(root,k);
            return 0;
        }
        int leftd = c(root->left,target,k);
        if(leftd!=-1){
            if(leftd+1==k){
                a.push_back(root->val);
            }
            else{
                depth(root->right,k-leftd-2);
            }
            return 1+leftd;
        }
        int rightd = c(root->right,target,k);
        if(rightd!=-1){
             if(rightd+1==k){
                a.push_back(root->val);
            }
            else{
                depth(root->left,k-rightd-2);
            }
            return 1+rightd;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        c(root,target,k);
        return a;
    }
};