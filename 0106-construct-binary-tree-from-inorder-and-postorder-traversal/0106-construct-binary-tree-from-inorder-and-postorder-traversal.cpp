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
    int findPosition(vector<int>& in, int inStart, int inEnd, int ele){
        for(int i=inStart;i<=inEnd;i++){
            if(in[i] == ele){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& post, vector<int>& in, int& index, int inStart, int inEnd, int n){
        if(index < 0 || inStart > inEnd){
            return NULL;
        }
        
        int ele = post[index--];
        TreeNode* root = new TreeNode(ele);
        
        int position = findPosition(in, inStart, inEnd, ele);
        
        root->right = solve(post, in, index, position+1, inEnd, n);
        root->left = solve(post, in, index, inStart, position-1, n);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = post.size();
        int postIndex = n-1;
        TreeNode* head = solve(post, in, postIndex, 0, n-1, n);
        return head;
    }
};