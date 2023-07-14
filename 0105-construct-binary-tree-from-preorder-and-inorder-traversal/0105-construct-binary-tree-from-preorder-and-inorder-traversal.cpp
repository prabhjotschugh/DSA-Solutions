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
    
    TreeNode* solve(vector<int>& pre, vector<int>& in, int& index, int inStart, int inEnd, int n){
        if(index >= n || inStart > inEnd){
            return NULL;
        }
        
        int ele = pre[index++];
        TreeNode* root = new TreeNode(ele);
        
        int position = findPosition(in, inStart, inEnd, ele);
        
        root->left = solve(pre, in, index, inStart, position-1, n);
        root->right = solve(pre, in, index, position+1, inEnd, n);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int preIndex = 0;
        TreeNode* head = solve(pre, in, preIndex, 0, n-1, n);
        return head;
    }
};