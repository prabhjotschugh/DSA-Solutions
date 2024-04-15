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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lf = heightleft(root);
        int rt = heightright(root);

        if(lf==rt){
            return (1<<lf)-1;
        }
        else{
           return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
    int heightleft(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height; 
    }

    int heightright(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
    return height;
    }
};