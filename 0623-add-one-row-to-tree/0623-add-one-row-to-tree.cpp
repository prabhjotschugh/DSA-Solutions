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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* new_node = new TreeNode(val, root, nullptr);
            return new_node;
        }

        queue<TreeNode*> q;
        int cur_depth = 1;
        if(root) {
            q.push(root);
        }
        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                auto node = q.front();
                q.pop();
                if(cur_depth == depth-1) {
                    TreeNode* new_left_node = new TreeNode(val, node->left, nullptr);
                    TreeNode* new_right_node = new TreeNode(val, nullptr, node->right);
                    node->left = new_left_node;
                    node->right = new_right_node;
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            cur_depth++;
        }
        return root;
    }
};