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
#include<algorithm>
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        int h = 0;
        unordered_map<int,int> ump;
        queue<TreeNode*> que;
        que.push(root);
        ump[0] = root->val;
        unordered_map<TreeNode*, TreeNode*> ans;
        while(!que.empty()){
            int size = que.size();
            //h is the height of the tree
            h++;
            for(int i=0;i<size;i++){
                TreeNode* num = que.front();
                que.pop();
                //cout<<num->left<<" "<<num->right<<endl;
                if(num->left){
                    que.push(num->left);
                    ump[h] = ump[h] + num->left->val;
                }
                //cout<<num->left<<" "<<num->right<<endl;
                if(num->right){
                    que.push(num->right);
                    ump[h] = ump[h] + num->right->val;
                }
                //cout<<num->left<<" "<<num->right<<endl;
            }
        }
        //replacing the values
        
        que.push(root);
        h = 0;
        root->val = 0;
        while(!que.empty()){
            int size = que.size();
            h++;
            for(int i=0;i<size;i++){
                TreeNode* num = que.front();
                que.pop();
                int l=0,r=0;
                //cout<<l<<" "<<r<<endl;
                if(num->left){
                    l = num->left->val;
                }
                //cout<<l<<" "<<r<<endl;
                if(num->right){
                    r = num->right->val;
                }
                //cout<<l<<" "<<r<<endl;
                
                //cout<<num->left<<" "<<num->right<<endl;
                if(num->left){
                    que.push(num->left);
                    num->left->val = ump[h]-l-r;
                }
                //cout<<num->left<<" "<<num->right<<endl;
                if(num->right){
                    que.push(num->right);
                    num->right->val = ump[h]-l-r;
                }
                //cout<<num->left<<" "<<num->right<<endl;
            }
        }
        return root;
    }
};